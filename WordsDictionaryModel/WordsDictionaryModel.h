#ifndef WORDSDICTIONARYMODEL_H
#define WORDSDICTIONARYMODEL_H

#include <QStandardItemModel>
#include <QMap>
#include <QString>
#include <WordsDictionary/abstractwordsdictionary.h>

class WordsDictionaryModel : public QStandardItemModel
{
    Q_OBJECT
public:
    WordsDictionaryModel(QObject *parent = nullptr);
    ~WordsDictionaryModel() override
    {
        ;
    }
    void addDict(const QMap<QString, QList<ESpeechPart> > &dict);


protected:
    QMap<QString, uint16_t> mDict;

private:
    void buildModel();
};

#endif // WORDSDICTIONARYMODEL_H
