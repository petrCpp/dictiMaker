#include "AppController.h"
#include <QApplication>
#include <AppFabric/WinWidgetsAppFabric.h>

AppController::AppController(EOsType osType, QObject *parent) :
        QObject(parent),
        mModel(new WordsDictionaryModel(this)),
        appInfo(new CApplicationInfo)
{
    // Создаем подходящую фабрику для создания компонентов приложения
    std::unique_ptr<AbstractAppFabric> appFabric = selectOs(osType);
    // Создаем компоненты приложения
    mWordsDict = appFabric->createDictionary();
    mGui = appFabric->createGui();
    mWordsFinder = appFabric->createWordsFinder();
    // Связываем компоненты друг с другом
    mGui->setGuiCommandsInterface(this);
    mGui->setDictionaryModel(mModel);
    mWordsFinder->setWordsFinderEvents(this);
    mGui->renderTotalWordsCount(mWordsDict->words().size());
    mModel->setWordDictionary(mWordsDict.get());

    mGui->setAppDescription(appInfo->getAppDescription());
    mGui->setAppName(appInfo->getApplicationName());
    mGui->setAppVersion(appInfo->getAppVersion());
    mGui->setAppBuildDate(appInfo->getAppBuildDate());
    mGui->setContacts(appInfo->getContacts());
    mGui->setMyPhoto(appInfo->getmyPhoto());
    mGui->setDictionaryGeometry();
}


std::unique_ptr<AbstractAppFabric>&& AppController::selectOs(EOsType osType)
{
    switch(osType)
    {
    case EOsType::win_10:
        mFabric.reset(new WinWidgetsAppFabric);
    default:
        mFabric.reset(new WinWidgetsAppFabric);
    }
    return std::move(mFabric);
}


void AppController::openTextFileToFindWords(const QString &fileName)
{
    //mWordsFinder->setDocumentPath(fileName);
    //CBasicErrorType err;
    mWordsFinder->startFindWords(fileName);
    //{
        //mGui->showErrorMessage(err);
    //}
}

void AppController::setDictSource(const QString &source)
{
    mWordsDict->setSource(source);
}


void AppController::saveDictionary(EWordDictSource source)
{
    if(source == EWordDictSource::file)
    {
        mWordsDict->setDictName(mGui->getDictName());
        mWordsDict->setDictLanguage(mGui->getLanguage());
        mWordsDict->saveData();
    }
}


void AppController::loadDictionary(EWordDictSource source)
{
    if(source == EWordDictSource::file)
    {
        mWordsDict->loadData();
        mGui->renderDictName(mWordsDict->getDictName());
        mGui->renderLanguage(mWordsDict->getDictLanguage());
        mGui->renderTotalWordsCount(mWordsDict->words().size());
        mModel->clear();
        mModel->addWords(mWordsDict->words());
        mGui->setDictionaryGeometry();
    }
}


void AppController::closeApp()
{
    QApplication::exit(0);
}


// ******************** WordsFinderEventsInterface implementation **************
void AppController::percentegesCompleted(float perc)
{
    mGui->redrawPercentage(perc);
}


void AppController::completed(EWordsFinderResult result)
{
    if(result == EWordsFinderResult::succes)
    {
        mWordsDict->appendWords(mWordsFinder->getFoundWords());
        mModel->addWords(mWordsDict->words());
        mGui->setDictionaryGeometry();
    }
    mGui->renderTotalWordsCount(mWordsDict->words().size());
}
