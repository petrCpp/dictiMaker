#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    redrawPercentage(100.0);

    this->show();


    connect(ui->actionOpen_text_file_for_find_new_words,
            SIGNAL(triggered(bool)), this, SLOT(onOpenTextFile()),
            Qt::DirectConnection);



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

void MainWindow::setGuiCommandsInterface(GuiCommandsInterface *cmdInterf)
{
    mCmdInterf = cmdInterf;
}

void MainWindow::setDictionaryModel(QAbstractItemModel *model)
{
    ui->tableView->setModel(model);
}

void MainWindow::renderTotalWordsCount(int totalWordsCount)
{

}

void MainWindow::renderNewFoundWordsCount(int newWordsCount)
{

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

void MainWindow::renderTotalWords(const QStringList &words)
{

}
