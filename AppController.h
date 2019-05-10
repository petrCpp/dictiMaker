#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include <QObject>
#include "appconfig.h"
#include <AppFabric/AbstractAppFabric.h>
#include <Gui/GuiInterface/guiinterface.h>
#include <WordsDictionary/abstractwordsdictionary.h>
#include <WordsFinder/abstractwordsfinder.h>
#include <WordsDictionaryModel/WordsDictionaryModel.h>
#include <memory>
#include <AppInfo/capplicationinfo.h>

class AppController : public QObject, public GuiCommandsInterface,
                        public WordsFinderEventsInterface
{
    Q_OBJECT
public:
    explicit AppController(EOsType osType, QObject *parent = nullptr);
    ~AppController() override
    {
        ;
    }
    std::unique_ptr<AbstractAppFabric> &&selectOs(EOsType osType);

    // GuiCommandsInterface implementation
    void openTextFileToFindWords(const QString & fileName) override;
    void setDictSource(const QString &source) override;
    void saveDictionary(EWordDictSource source) override;
    void loadDictionary(EWordDictSource source) override;
    void closeApp() override;


    // WordsFinderEventsInterface implementation
    void percentegesCompleted(float perc) override;
    void completed(EWordsFinderResult result) override;

signals:

public slots:

private:
    std::unique_ptr<GuiInterface> mGui;
    std::unique_ptr<AbstractWordsDictionary> mWordsDict;
    std::unique_ptr<AbstractWordsFinder> mWordsFinder;
    WordsDictionaryModel *mModel;
    std::unique_ptr<AbstractAppFabric> mFabric;
    CApplicationInfo *appInfo;
};

#endif // APP_CONTROLLER_H
