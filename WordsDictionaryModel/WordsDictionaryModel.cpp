#include "WordsDictionaryModel.h"
#include <QVariant>
#include <QDebug>

WordsDictionaryModel::WordsDictionaryModel(QObject *parent):
        QStandardItemModel(parent)
{

}

void WordsDictionaryModel::setWordDictionary(AbstractWordsDictionary *dict)
{
    mDict = dict;
}

void WordsDictionaryModel::addWords(const QMap<QString, QList<ESpeechPart>> &words)
{
    QMap<QString, QList<ESpeechPart>>::const_iterator it;
    for(it = words.begin(); it != words.end(); ++it)
    {
        if(!mWords.contains(it.key()))
        {
            mWords.insert(it.key(), it.value());
        }
    }
    buildModel();
}


// will be redraw model by merging method (in future).
void WordsDictionaryModel::buildModel()
{
    if(mDict == nullptr)
    {
        qDebug() << "A dictionary should be established before using this method";
        return;
    }

    QMap<QString, QList<ESpeechPart>>::const_iterator it;
    this->blockSignals(true); // To accelerating redraw views
    this->clear();
    QStandardItem *item = new QStandardItem(QString("Word"));
    this->setHorizontalHeaderItem(0, item);

    QMap<ESpeechPart, QString> spNames = mDict->getSpeachPartsNames();

    for(int i=0; i< static_cast<int>(ESpeechPart::partsCount); i++)
    {
        QString name;
        if(spNames.contains(static_cast<ESpeechPart>(i)))
        {
            name = spNames[static_cast<ESpeechPart>(i)];
        }
        //if(name != "")
        //{
        item = new QStandardItem(name);
        this->setHorizontalHeaderItem(i+1, item);
        //}
    }

    this->setColumnCount(1+static_cast<int8_t>(ESpeechPart::partsCount));
    this->setRowCount(mWords.size());
    int i=0;
    QString lastKey = mWords.lastKey();
    for(it = mWords.begin(); it != mWords.end(); ++it)
    {
        if(it.key() == lastKey)
        {
            this->blockSignals(false);
        }
        QStandardItem *item = new QStandardItem(it.key());
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        this->setItem(i, 0, item);

        QList<ESpeechPart> parts = it.value();
        for(int j=0; j<static_cast<int>(ESpeechPart::partsCount); j++)
        {
            QStandardItem *partItem = new QStandardItem();
            partItem->setFlags(Qt::ItemIsSelectable |
                               Qt::ItemIsEditable |
                               Qt::ItemIsUserCheckable |
                               Qt::ItemIsEnabled);
            this->setItem(i, j+1, partItem);
            if(parts.contains(static_cast<ESpeechPart>(j)))
            {
                partItem->setCheckState(Qt::Checked);
            }
            else
            {
                partItem->setCheckState(Qt::Unchecked);
            }

        }


        //item = new QStandardItem();
        //item->setData(QVariant(arr), Qt::EditRole);
        //this->setItem(i, 1, item);
        i++;
    }
    this->blockSignals(false);
}
