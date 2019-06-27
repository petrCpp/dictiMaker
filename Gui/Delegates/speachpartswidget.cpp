#include "speachpartswidget.h"
#include "ui_speachpartswidget.h"

const QMap<ESpeechPart, QString> SpeachPartsWidget::mSpPatrtsNames
{
    {ESpeechPart::adjective, QObject::tr("adjective")},
    {ESpeechPart::adverb, QObject::tr("adverb")},
    {ESpeechPart::conjunction, QObject::tr("conjunction")},
    {ESpeechPart::foreignWord, QObject::tr("foreignWord")},
    {ESpeechPart::interjection, QObject::tr("interjection")},
    {ESpeechPart::nonWord, QObject::tr("nonWord")},
    {ESpeechPart::noun, QObject::tr("noun")},
    {ESpeechPart::numeral, QObject::tr("numeral")},
    {ESpeechPart::particle, QObject::tr("particle")},
    {ESpeechPart::preposition, QObject::tr("preposition")},
    {ESpeechPart::pronoun, QObject::tr("pronoun")},
    {ESpeechPart::shortAdjective, QObject::tr("shortAdjective")},
    {ESpeechPart::unknown, QObject::tr("unknown")},
    {ESpeechPart::verb, QObject::tr("verb")},
};

SpeachPartsWidget::SpeachPartsWidget(QWidget *parent) :
    QWidget(parent),
    mPrototype(new Ui::SpeachPartsWidget)
{
    mPrototype->setupUi(this);

    // Create widget items per prototype from form constructor
    SSpeachPartWidgets firstItem;
    firstItem.lbl = mPrototype->speachPartNameLbl;
    firstItem.layout = mPrototype->verticalLayout;
    firstItem.checkBox = mPrototype->speachPartSelChckBx;

    mWidgetItems.append(firstItem);

    for(int i=1; i!= static_cast<int>(ESpeechPart::unknown); ++i)
    {
        SSpeachPartWidgets item;
        item.lbl = new QLabel();
        item.lbl->setText(mSpPatrtsNames[static_cast<ESpeechPart>(i)]);
        item.checkBox = new QCheckBox();
        item.layout = new QVBoxLayout();
        item.layout->addWidget(item.lbl);
        item.layout->addWidget(item.checkBox);
        mWidgetItems.append(item);
        mPrototype->horizontalLayout->addLayout(item.layout);
    }
    //setMinimumHeight(50);
    //setMinimumWidth(400);

}

SpeachPartsWidget::~SpeachPartsWidget()
{
    delete mPrototype;
}

void SpeachPartsWidget::setValue(const QList<ESpeechPart> &parts)
{
    for(int i=0; i<mWidgetItems.size(); i++)
    {
        mWidgetItems[i].checkBox->setChecked(false);
    }

    for(int i = 0; i<parts.size(); i++)
    {
        int value = static_cast<const int>(parts.at(i));
        if(value < mWidgetItems.size())
        {
            mWidgetItems[value].checkBox->setChecked(true);
        }
    }
}

QList<ESpeechPart> SpeachPartsWidget::value() const
{
    QList<ESpeechPart> res;
    for(int i=0; i<mWidgetItems.size(); i++)
    {
        if(mWidgetItems[i].checkBox->checkState() == Qt::Checked)
        {
            res.append(static_cast<ESpeechPart>(i));
        }
    }
    return res;
}
