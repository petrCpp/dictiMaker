#ifndef WORDSFINDER1_H
#define WORDSFINDER1_H

#include <WordsFinder/abstractwordsfinder.h>
#include <WordsFinder/WordsFinder1/findwords1worker.h>
#include <QString>
#include <QObject>
#include <QThread>
#include <QMap>

class WordsFinder1 : public QObject, public AbstractWordsFinder
{
    Q_OBJECT
public:
    WordsFinder1(QObject *parent = nullptr);
    ~WordsFinder1() override;
    void setWordsFinderEvents(WordsFinderEventsInterface *events) override;
    //void setDocumentPath(const QString &fileName) override;
    bool startFindWords(const QString &fileName) override;
    const QMap<QString, uint16_t> &getFoundWords() override;
protected slots:
    void handleResults(QMap<QString, uint16_t> result);
    void onPercenteges(float perc);
signals:
    void startScanFile(const QString filename);


private:
    WordsFinderEventsInterface *mEvents {nullptr};
    //QString mFileName;
    FindWords1Worker *mWorker;
    QThread mWorkerThread;
    QMap<QString, uint16_t> mDict;
    bool mStateEddle {true};
};

#endif // WORDSFINDER1_H
