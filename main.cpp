#include <Gui/mainwindow.h>
#include <QApplication>
#include "AppController.h"

#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppController apInit(SELECTED_OS_TYPE);


    std::unique_ptr<int> ptr1;
    std::unique_ptr<int> ptr2;
    ptr2 = std::move(ptr1);

    //QScopedPointer<int> pointer1;
    //QScopedPointer<int> pointer2;
    //pointer2 = std::move(pointer1);


    //MainWindow w;
    //w.show();

    return a.exec();
}
