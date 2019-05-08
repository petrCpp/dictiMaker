#ifndef WORDSDICTIONARYMODEL_H
#define WORDSDICTIONARYMODEL_H

#include <QStandardItemModel>
#include <QMap>
#include <QString>

class WordsDictionaryModel : public QStandardItemModel
{
    Q_OBJECT
public:
    WordsDictionaryModel(QObject *parent = nullptr);
    ~WordsDictionaryModel() override
    {
        ;
    }
    void addDict(const QMap<QString, uint16_t> &dict);


protected:
    QMap<QString, uint16_t> mDict;

private:
    void buildModel();
};

#endif // WORDSDICTIONARYMODEL_H
