#include "capplicationinfo.h"

CApplicationInfo::CApplicationInfo(QObject *parent) : QObject(parent)
{

}

QString CApplicationInfo::getAppDescription()
{
    return tr(
    {"This application was especially created for demonstration "
     "my skills in the programming art."


                });
}

QString CApplicationInfo::getAppVersion()
{
    return PROGRAM_VERSION;
}

QString CApplicationInfo::getContacts()
{
    return tr("Abrosimov Petr \n"
              "Software Engineer \n"
              "Email: petruha_1@ngs.ru");
}

QPixmap CApplicationInfo::getmyPhoto()
{
    return QPixmap(":/resources/my_photo.jpg");
}
