#include "SpeachPartsDelegate.h"
//#include <QSpinBox>
#include <Gui/Delegates/speachpartswidget.h>

SpeachPartsDelegate::SpeachPartsDelegate(QObject *parent):
        QStyledItemDelegate(parent)
{

}

QWidget *SpeachPartsDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(&option);
    Q_UNUSED(&index);
    if(index.column() == 1)
    {
        SpeachPartsWidget *editor = new SpeachPartsWidget(parent);
        //editor->setFrame(false);
        //editor->setMinimum(0);
        //editor->setMaximum(100);
        return editor;
    }
    else
    {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
}


void SpeachPartsDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.column() == 1)
    {
        QByteArray value = index.model()->data(index, Qt::EditRole).toByteArray();

        SpeachPartsWidget *widg = qobject_cast<SpeachPartsWidget*>(editor);

        QList<ESpeechPart> parts;
        parts.reserve(value.size());
        for(int i = 0; i<value.size(); i++)
        {
            parts.append(static_cast<ESpeechPart>(value.at(i)));
        }
        widg->setValue(parts);
    }
    else
    {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void SpeachPartsDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(index.column() == 1)
    {
        SpeachPartsWidget *widg = qobject_cast<SpeachPartsWidget*>(editor);
        //spinBox->interpretText();
        QList<ESpeechPart> value = widg->value();
        QByteArray arr(value.size(), 0);
        for(int i = 0; i<value.size(); i++)
        {
            arr[i] = static_cast<const char>(value.at(i));
        }
        model->setData(index, QVariant(arr), Qt::EditRole);
    }
    else
    {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void SpeachPartsDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 1)
    {
        editor->setGeometry(option.rect);
    }
    else
    {
        QStyledItemDelegate::updateEditorGeometry(editor, option, index);
    }
}

QSize SpeachPartsDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 1)
    {
        /*SpeachPartsWidget *widg = qobject_cast<SpeachPartsWidget*>(editor);
        //spinBox->interpretText();
        QList<ESpeechPart> value = widg->value();
        QByteArray arr(value.size(), 0);
        for(int i = 0; i<value.size(); i++)
        {
            arr[i] = static_cast<const char>(value.at(i));
        }
        model->setData(index, QVariant(arr), Qt::EditRole);*/

        return QSize(50, 500);
    }
    else
    {
        return QStyledItemDelegate::sizeHint(option, index);
    }
}

void SpeachPartsDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(index);
}
