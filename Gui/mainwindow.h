#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Gui/aboutwindow.h>
#include <Gui/GuiInterface/guiinterface.h>
#include <Gui/Delegates/SpeachPartsDelegate.h>
#include <CBasicErrorType.h>
#include <QPointer>
#include <memory>
#include <QPixmap>
#include <QList>
#include <WordsDictionary/abstractwordsdictionary.h>

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
    void onSaveDictFile();
    void onLoadDictFromFile();
    void onAbout();
private:
    void setGuiCommandsInterface(GuiCommandsInterface *cmdInterf) override;
    void setDictionaryModel(QAbstractItemModel *model) override;
    void setDictionaryGeometry() override;
    void renderTotalWordsCount(int totalWordsCount) override;
    void renderNewFoundWordsCount(int newWordsCount) override;
    void renderTotalWords(const QStringList &words) override;
    void renderLanguage(const QString &lang) override;
    void renderDictName(const QString &dictName) override;
    QString getLanguage() override;
    QString getDictName() override;
    void showErrorMessage(const CBasicErrorType &err) override;
    void redrawPercentage(float perc) override;
    void setAppDescription(const QString &descr) override {mDescr = descr;}
    void setAppName(const QString &appName) override;
    void setAppVersion(const QString &version) override {mVersion = version;}
    void setAppBuildDate(const QString &buildDate) override {mBuildDate = buildDate;}
    void setContacts(const QString &contacts) override {mContacts = contacts;}
    void setMyPhoto(const QPixmap &photo) override;
    GuiCommandsInterface *mCmdInterf {nullptr};

    struct ColProperties
    {
        uint16_t width;
    };

    Ui::MainWindow *ui;
    std::unique_ptr<AboutWindow> mAbout;
    SpeachPartsDelegate *mDelegate;
    QString mDescr;
    QString mVersion;
    QString mBuildDate;
    QString mContacts;
    QPixmap mMyPhoto;
    const QList<ColProperties> mTableColProperties;
};

#endif // MAINWINDOW_H
