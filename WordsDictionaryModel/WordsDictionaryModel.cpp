#include "WordsDictionaryModel.h"


WordsDictionaryModel::WordsDictionaryModel(QObject *parent):
        QStandardItemModel(parent)
{

}

void WordsDictionaryModel::addDict(const QMap<QString, QList<ESpeechPart>> &dict)
{
    QMap<QString, QList<ESpeechPart>>::const_iterator it;
    for(it = dict.begin(); it != dict.end(); ++it)
    {
        if(!mDict.contains(it.key()))
        {
            mDict.insert(it.key(), 0);
        }
    }
    buildModel();
}


// обновляем модель методом слияния (в будущем). Сейчас по-простому
void WordsDictionaryModel::buildModel()
{
    QMap<QString, uint16_t>::const_iterator it;
    this->clear();
    this->setColumnCount(2);
    this->setRowCount(mDict.size());
    int i = 0;
    for(it = mDict.begin(); it != mDict.end(); ++it)
    {
        QStandardItem *item = new QStandardItem(it.key());
        this->setItem(i, 0, item);
        i++;
    }
}
