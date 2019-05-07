#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Gui/GuiInterface/guiinterface.h>
#include <CBasicErrorType.h>
#include <QPointer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public GuiInterface
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow() override;


protected slots:
    void onOpenTextFile();

private:
    void setGuiCommandsInterface(GuiCommandsInterface *cmdInterf) override;
    void setDictionaryModel(QAbstractItemModel *model) override;
    void renderTotalWordsCount(int totalWordsCount) override;
    void renderNewFoundWordsCount(int newWordsCount) override;
    void renderTotalWords(const QStringList &words) override;
    void showErrorMessage(const CBasicErrorType &err) override;
    void redrawPercentage(float perc) override;
    GuiCommandsInterface *mCmdInterf {nullptr};
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
