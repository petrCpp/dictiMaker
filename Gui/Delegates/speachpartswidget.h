#ifndef SPEACHPARTSWIDGET_H
#define SPEACHPARTSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <WordsDictionary/abstractwordsdictionary.h>

namespace Ui {
class SpeachPartsWidget;
}

class SpeachPartsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpeachPartsWidget(QWidget *parent = 0);
    ~SpeachPartsWidget();
    void setValue(const QList<ESpeechPart> &parts);
    QList<ESpeechPart> value() const;
private:
    struct SSpeachPartWidgets
    {
        QVBoxLayout *layout;
        QLabel *lbl;
        QCheckBox *checkBox;
    };
    static const QMap<ESpeechPart, QString> mSpPatrtsNames;
    QList<SSpeachPartWidgets> mWidgetItems;
    Ui::SpeachPartsWidget *mPrototype;
    //void labelClone(QLabel *dest, const QLabel *source);
};

#endif // SPEACHPARTSWIDGET_H
