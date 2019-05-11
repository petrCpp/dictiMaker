#ifndef FINDWORDS1WORKER_H
#define FINDWORDS1WORKER_H

#include <QObject>
#include <QString>
#include <QQueue>
#include <memory>
#include <QMap>
#include <QFile>

class FindWords1Worker : public QObject
{
    Q_OBJECT
public:
    ~FindWords1Worker() override
    {
        ;
    }
public slots:
    void startScanFile(const QString filename);
    void terminate();
signals:
    void resultReady(QMap<QString, uint16_t> result);
    void errorResult(QString errDescription);
    void percenteges(float perc);

private slots:
    void scanFile();
    bool scanFilePortion(QFile &file, int64_t startPos, int64_t porcByteCount, QMap<QString, uint16_t> &dictionary);

protected:
    const uint32_t OFFSET_SIMBOLS = 70;
    const uint32_t PORC_BYTE_COUNT = 100000;
    QMap<QString, uint16_t> mDictionary;
    QQueue<QString> tasksFiles;
    bool mScaningFileState {false};
    bool mTerminate {false};
    static QString remove0D0A(const QString &str);
};






/*class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    Controller() {
        Worker *worker = new Worker;
        worker->moveToThread(&workerThread);
        connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(this, &Controller::operate, worker, &Worker::doWork);
        connect(worker, &Worker::resultReady, this, &Controller::handleResults);
        workerThread.start();
    }
    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void handleResults(const QString &);
signals:
    void operate(const QString &);
};*/

#endif // FINDWORDS1WORKER_H
