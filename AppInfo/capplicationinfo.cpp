#include "capplicationinfo.h"

CApplicationInfo::CApplicationInfo(QObject *parent) : QObject(parent)
{

}

QString CApplicationInfo::getApplicationName()
{
    return tr("Dictionary Maker");
}

QString CApplicationInfo::getAppDescription()
{
    const QString itemsFont = "<font size=\"3\" color=#0B890B>";
    const QString notImplementedFont = "<font size=\"3\" color=#740808>";
    return tr(
    {"<p><font size=\"3\" color=#1D1B51>"
     "This application was especially created for demonstration "
     "my skills in the programming art. It intended to "
     "automatically create a dictionary and write it to a special "
     "file with the dct extension in JSON format. "
     "The application also allows you to write a dictionary to the database.</p><br>"

     "<b><font size=\"3\" color=#0A3051>In particular this example project show possession of such "
     "skills as:</b>"
     "<ul>"
     "<li>%1Modern c++"
     "<li>%1Multithreading"
     "<li>%1Design patterns"
     "<li>%1Basic algoritms & Data structures"
     "<li>%1Smart pointers"
     "<li>%1Qt widgets"
     "<li>%1JSON serialization"
     "<li>%1Qml technology %2[not yet implemented]"
     "<li>%1Data bases %2[not yet implemented]"
     "<li>%1Qt localization %2[not yet implemented],"
     "<li>%1Interprocess communication %2[not yet implemented]"
     "<li>%1TCP/IP communication %2[not yet implemented]"
     "<li>%1Unit testing %2[not yet implemented]</ul>"
                }).arg(itemsFont).
            arg(notImplementedFont);
}

QString CApplicationInfo::getAppVersion()
{
    return tr("<b><font size=\"3\" color=#00512E>%1 </b>"
              ).arg(PROGRAM_VERSION);
}

QString CApplicationInfo::getAppBuildDate()
{
    return QString(__DATE__);
}

QString CApplicationInfo::getContacts()
{
    return tr("<b><font size=\"3\" color=#244A8C> Abrosimov Petr</b><br>"
              "<b><font size=\"3\" color=#500B8C> Software Engineer</b><br>"
              "<b><font size=\"3\" color=#00512E> Email:</b>"
              "<a href=\"mailto:petruha_1@ngs.ru\"> <cite>petruha_1@ngs.ru</cite></a>  <br>");
}

QPixmap CApplicationInfo::getmyPhoto()
{
    return QPixmap(":/resources/my_photo.jpg");
}
