#include "capplicationinfo.h"

CApplicationInfo::CApplicationInfo(QObject *parent) : QObject(parent)
{

}

QString CApplicationInfo::getAppDescription()
{
    return tr(
    {"This application was especially created for demonstration "
     "my skills in the programming art. It intended to "
     "automatically create a dictionary and write it to a special "
     "file with the dct extension in JSON format. "
     "The application also allows you to write a dictionary to the database. \n\n"
     "In particular this example project show possession of such "
     "skills as:\n"
     "-Modern c++,\n"
     "-Multithreading,\n"
     "-Design patterns,\n"
     "-Basic algoritms & Data structures,\n"
     "-Smart pointers,\n"
     "-Qt widgets,\n"
     "-JSON serialization, \n"
     "-Qml technology [not yet implemented],\n"
     "-Data bases [not yet implemented],\n"
     "-Qt localization [not yet implemented],\n"
     "-Interprocess communication [not yet implemented],\n"
     "-TCP/IP communication [not yet implemented],\n"
     "-Unit testing [not yet implemented]"
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
