#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
}

void AboutWindow::setAppDescription(const QString &descr)
{
    //mDescr = descr;
    ui->descriptionEdt->setText(descr);
}

void AboutWindow::setAppVersion(const QString &version)
{
    //mVersion = version;

    ui->progVersionLbl->setText(QString("<b>%1</b> <i></i>").arg(version));
}

void AboutWindow::setContacts(const QString &contacts)
{
    ui->contactsEdt->setText(contacts);
}

void AboutWindow::setMyPhoto(const QPixmap &myPhoto)
{
    ui->myPhotoLbl->setPixmap(myPhoto);
}
