#include "WinWidgetsAppFabric.h"
#include <Gui/GuiInterface/guiinterface.h>
#include <mainwindow.h>
#include <WordsDictionary/WordsDictionary1.h>
#include <WordsFinder/WordsFinder1/wordsfinder1.h>

WinWidgetsAppFabric::WinWidgetsAppFabric()
{

}


std::unique_ptr<GuiInterface> &&WinWidgetsAppFabric::createGui()
{
    mGui.reset(new MainWindow);
    return std::move(mGui);
}


std::unique_ptr<AbstractWordsDictionary>&& WinWidgetsAppFabric::createDictionary()
{
    mDict.reset(new WordsDictionary1);
    return std::move(mDict);
}


std::unique_ptr<AbstractWordsFinder>&& WinWidgetsAppFabric::createWordsFinder()
{
    mFinder.reset(new WordsFinder1);
    return std::move(mFinder);
}
