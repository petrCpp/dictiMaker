#include "wordsfinder1.h"

WordsFinder1::WordsFinder1(QObject *parent):
        QObject(parent),
        mWorker(new FindWords1Worker)
{
    mWorker->moveToThread(&mWorkerThread);
    connect(&mWorkerThread, &QThread::finished, mWorker, &QObject::deleteLater);
    connect(mWorker, &FindWords1Worker::resultReady, this, &WordsFinder1::handleResults,
            Qt::QueuedConnection);
    connect(mWorker, &FindWords1Worker::percenteges, this, &WordsFinder1::onPercenteges,
            Qt::QueuedConnection);
    connect(this, &WordsFinder1::startScanFile, mWorker, &FindWords1Worker::startScanFile,
            Qt::QueuedConnection);
    mWorkerThread.start();
}


void WordsFinder1::setWordsFinderEvents(WordsFinderEventsInterface *events)
{
    mEvents = events;
}


/*void WordsFinder1::setDocumentPath(const QString &fileName)
{
    mFileName = fileName;
}*/


bool WordsFinder1::startFindWords(const QString &fileName /*, CBasicErrorType &err*/)
{
    if(!mStateEddle)
    {
        return false;
    }
    emit startScanFile(fileName);
    //QObject::metaObject()->invokeMethod(mWorker, "doWork", Qt::AutoConnection);
    mStateEddle = false;
    return true;
}


WordsFinder1::~WordsFinder1()
{
    mWorkerThread.quit();
    mWorkerThread.wait();
}


const QMap<QString, uint16_t>& WordsFinder1::getFoundWords()
{
    return mDict;
}

void WordsFinder1::handleResults(QMap<QString, uint16_t> result)
{
    mDict = result;
    mStateEddle = true;
    if(mEvents != nullptr)
    {
        mEvents->completed(EWordsFinderResult::succes);
    }
}

void WordsFinder1::onPercenteges(float perc)
{
    mEvents->percentegesCompleted(perc);
}
