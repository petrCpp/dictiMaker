#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class AboutWindow;
}


class AboutWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AboutWindow(QWidget *parent = nullptr);
    void setAppDescription(const QString &descr);
    void setAppVersion(const QString &version);
    void setContacts(const QString &contacts);
    void setMyPhoto(const QPixmap &myPhoto);
signals:

public slots:

private:
    //QString mDescr;
    //QString mVersion;
    Ui::AboutWindow *ui;

};

#endif // ABOUTWINDOW_H
