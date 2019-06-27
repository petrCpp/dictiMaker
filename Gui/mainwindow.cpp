#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <Gui/GuiInterface/guicommandsinterface.h>
#include <QMessageBox>
#include <QTableView>
#include <QItemDelegate>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mDelegate(new SpeachPartsDelegate(this)),
    mTableColProperties
    ({
    {120},
    {40},
    {60},
    {100},
    {60},
    {60},
    {40},
    {60},
    {70},
    {75},
    {50},
    {75},
    {60},
    {80},
    {70},
    })
{
    ui->setupUi(this);

    //QTableView *view = new QTableView(this);
    //QItemDelegate

    redrawPercentage(100.0);

    this->show();

    connect(ui->actionOpenDBDictionary,
            &QAction::triggered, this, [this]()
    {
        QMessageBox box;
        box.setText(tr("It option is not yet implemented"));
        box.exec();
    }, Qt::DirectConnection);

    connect(ui->actionSave_dictionary_DB,
            &QAction::triggered, this, [this]()
    {
        QMessageBox box;
        box.setText(tr("It option is not yet implemented"));
        box.exec();
    }, Qt::DirectConnection);

    connect(ui->actionOpen_text_file_for_find_new_words,
            SIGNAL(triggered(bool)), this, SLOT(onOpenTextFile()),
            Qt::DirectConnection);
    connect(ui->actionSave_dictionary_file, &QAction::triggered,
            this, &MainWindow::onSaveDictFile, Qt::DirectConnection);

    connect(ui->actionOpen_dictionary_from_file, &QAction::triggered,
            this, &MainWindow::onLoadDictFromFile, Qt::DirectConnection);

    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::onAbout,
            Qt::DirectConnection);

    connect(ui->actionexit, &QAction::triggered, this, [this]()
    {
        mCmdInterf->closeApp();

    }, Qt::DirectConnection);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenTextFile()
{
    if(mCmdInterf!= nullptr)
    {
        QString fileName = QFileDialog::getOpenFileName(this,
                tr("Выберите файл настроек"), "", tr("Текстовые файлы (*.txt)"));

        //QString fileName = "C:/Users/Petr/Desktop/текст.txt";
        // Если файл не выбран, выходим
        if (fileName.isEmpty()) return;
        mCmdInterf->openTextFileToFindWords(fileName);
    }
}

void MainWindow::onSaveDictFile()
{
    if(mCmdInterf!= nullptr)
    {
        QString fileName = QFileDialog::getSaveFileName(this,
                tr("Выберите файл словаря"), "", tr("Файл словаря (*.dct)"));

        //QString fileName = "C:/Users/Petr/Desktop/текст.txt";
        // Если файл не выбран, выходим
        if (fileName.isEmpty()) return;
        mCmdInterf->setDictSource(fileName);
        mCmdInterf->saveDictionary(EWordDictSource::file);
    }
}

void MainWindow::onLoadDictFromFile()
{
    if(mCmdInterf!= nullptr)
    {
        QString fileName = QFileDialog::getOpenFileName(this,
                tr("Выберите файл настроек"), "", tr("Файл словаря (*.dct)"));

        //QString fileName = "C:/Users/Petr/Desktop/текст.txt";
        // Если файл не выбран, выходим
        if (fileName.isEmpty()) return;
        mCmdInterf->setDictSource(fileName);
        mCmdInterf->loadDictionary(EWordDictSource::file);
    }
}

void MainWindow::onAbout()
{
    if(mAbout == nullptr)
    {
        mAbout.reset(new AboutWindow);
        mAbout->setAppDescription(mDescr);
        mAbout->setAppVersion(mVersion);
        mAbout->setAppBuildDate(mBuildDate);
        mAbout->setContacts(mContacts);
        mAbout->setMyPhoto(mMyPhoto);
    }
    mAbout->show();



}

void MainWindow::setGuiCommandsInterface(GuiCommandsInterface *cmdInterf)
{
    mCmdInterf = cmdInterf;
}

void MainWindow::setDictionaryModel(QAbstractItemModel *model)
{
    ui->tableView->setModel(model);
    //std::unique_ptr<QAbstractItemDelegate> deleg(ui->tableView->
    //                                             itemDelegate());
    //ui->tableView->setItemDelegate(mDelegate);
}

void MainWindow::setDictionaryGeometry()
{
    //ui->tableView->setColumnWidth(1, 500);

    for(int i=0; i<mTableColProperties.size(); i++)
    {
        ui->tableView->setColumnWidth(i, mTableColProperties[i].width);
        //ui->tableView->setRowHeight(i, 60);
    }
}

void MainWindow::renderTotalWordsCount(int totalWordsCount)
{
    ui->dictWordsNumberLbl->setText(QString::number(totalWordsCount));
}

void MainWindow::renderNewFoundWordsCount(int newWordsCount)
{
    Q_UNUSED(newWordsCount);
}

void MainWindow::showErrorMessage(const CBasicErrorType &err)
{
    QMessageBox msgBox;
    msgBox.setText(err.errorSource() + " " + QString::number(err.errorCode())+
                   " " + err.errorDescription());
}

void MainWindow::redrawPercentage(float perc)
{
    if(perc >= 100 || perc<0)
    {
        ui->progressBar->setVisible(false);
    }
    else
    {
        ui->progressBar->setVisible(true);
        ui->progressBar->setValue(perc);
    }
}

void MainWindow::setAppName(const QString &appName)
{
    this->setWindowTitle(appName);
}

void MainWindow::setMyPhoto(const QPixmap &photo)
{
    mMyPhoto = photo;
}


void MainWindow::renderTotalWords(const QStringList &words)
{
    Q_UNUSED(words);
}

void MainWindow::renderLanguage(const QString &lang)
{
    ui->languageEdt->setText(lang);
}

void MainWindow::renderDictName(const QString &dictName)
{
    ui->dictNameEdt->setText(dictName);
}

QString MainWindow::getLanguage()
{
    return ui->languageEdt->text();
}

QString MainWindow::getDictName()
{
    return ui->dictNameEdt->text();
}
