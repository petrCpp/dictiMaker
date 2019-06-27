#ifndef WORDSDICTIONARYMODEL_H
#define WORDSDICTIONARYMODEL_H

#include <QStandardItemModel>
#include <QMap>
#include <QString>
#include <WordsDictionary/abstractwordsdictionary.h>
#include <WordsDictionary/abstractwordsdictionary.h>

class WordsDictionaryModel : public QStandardItemModel
{
    Q_OBJECT
public:
    WordsDictionaryModel(QObject *parent = nullptr);
    void setWordDictionary(AbstractWordsDictionary *dict);
    ~WordsDictionaryModel() override
    {
        ;
    }
    void addWords(const QMap<QString, QList<ESpeechPart> > &words);


protected:
    AbstractWordsDictionary *mDict {nullptr};
    QMap<QString, QList<ESpeechPart>> mWords;

private:
    void buildModel();
};

#endif // WORDSDICTIONARYMODEL_H
