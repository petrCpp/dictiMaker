#ifndef SPEACHPARTSDELEGATE_H
#define SPEACHPARTSDELEGATE_H

#include <QStyledItemDelegate>

class SpeachPartsDelegate : public QStyledItemDelegate
{
Q_OBJECT
public:
   SpeachPartsDelegate(QObject *parent = nullptr);

   QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const override;

   void setEditorData(QWidget *editor, const QModelIndex &index) const override;
   void setModelData(QWidget *editor, QAbstractItemModel *model,
                     const QModelIndex &index) const override;

   void updateEditorGeometry(QWidget *editor,
       const QStyleOptionViewItem &option, const QModelIndex &index) const override;
   QSize sizeHint(const QStyleOptionViewItem &option,
                       const QModelIndex &index) const override;
   void paint(QPainter *painter, const QStyleOptionViewItem &option,
                    const QModelIndex &index) const override;

};

#endif // SPEACHPARTSDELEGATE_H
