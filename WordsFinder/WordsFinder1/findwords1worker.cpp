#include "findwords1worker.h"
#include <QTimer>
#include <QEventLoop>


void FindWords1Worker::startScanFile(const QString filename)
{
    if(!mScaningFileState)
    {
        mScaningFileState = true;
        mTerminate = false;
        QTimer::singleShot(0, this, &FindWords1Worker::scanFile);
    }
    tasksFiles.enqueue(filename);
}

void FindWords1Worker::terminate()
{
    tasksFiles.clear();
    mTerminate = true;
}

void FindWords1Worker::scanFile()
{
    mScaningFileState = true;
    mDictionary.clear();
    bool err = false;
    QString errMessage;
    while(1)
    {
        if(tasksFiles.isEmpty())
        {
            break;
        }
        QString fileName = tasksFiles.dequeue();
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly))
        {
            err = true;
            errMessage = tr("Не удалось открыть файл %1").arg(fileName);
            break;
        }
        if(mTerminate)
        {
            err = true;
            errMessage = tr("Прервано пользователем");
            break;
        }

        uint64_t pos = 0;
        uint64_t fileSize = file.size();
        float percentage = 0.0f;
        while(1)
        {
            if(scanFilePortion(file,
                               pos,
                               PORC_BYTE_COUNT,
                               mDictionary))
            {
                break;
            }
            pos += PORC_BYTE_COUNT-50;

            percentage = (100.0f *pos)/static_cast<float>(fileSize);
            emit percenteges(percentage);
            QEventLoop loop;
            loop.processEvents();
        }
    }
    emit percenteges(100.0);
    if(err)
    {
        errorResult(errMessage);
    }
    else
    {
        emit resultReady(mDictionary);
    }

    mScaningFileState = false;
}

bool FindWords1Worker::scanFilePortion(QFile &file, int64_t startPos,
                                       int64_t porcByteCount,
                                       QMap<QString, uint16_t> &dictionary)
{
    if(startPos >= file.size())
    {
        return true;
    }
    file.seek(startPos);
    QByteArray arr = file.read(porcByteCount);
    QString str(arr);

    const QRegExp word_expr(QString("\\b[a-zа-я]{2,32}\\b"), Qt::CaseInsensitive);
    const QRegExp sep_expr(QString("[^a-z^а-я]"), Qt::CaseInsensitive);
    int64_t cnt=0, cnt_end;
    int32_t dummy = 0;
    QString word;
    while(cnt<str.size())
    {
        cnt = str.indexOf(word_expr, cnt);
        if(cnt < 0) break;
        cnt_end = str.indexOf(sep_expr, cnt);
        if(cnt_end < 0) cnt_end = str.length()-1;
        word = str.mid(cnt, cnt_end-cnt);
        if(cnt_end < 0) break;
        cnt = cnt_end;
        if(!dictionary.contains(word)) { // Слово отсутствует в словаре
            dictionary.insert(word, dummy); // Добавляем слово, если оно отсутствует в
            // словаре
        }
    }

    if(arr.size() < porcByteCount)
    {
        return true;
    }
    else
    {
        return false;
    }
}
