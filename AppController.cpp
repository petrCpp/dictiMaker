#include "AppController.h"
#include <AppFabric/WinWidgetsAppFabric.h>

AppController::AppController(EOsType osType, QObject *parent) :
        QObject(parent),
        mModel(new WordsDictionaryModel(this))
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


void AppController::saveDictionary(EWordDictSource source)
{

}


void AppController::loadDictionary(EWordDictSource source)
{

}


void AppController::closeApp()
{

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
        mModel->addDict(mWordsFinder->getFoundWords());
    }
}
