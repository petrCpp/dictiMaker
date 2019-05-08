#ifndef WINWIDGETSAPPFABRIC_H
#define WINWIDGETSAPPFABRIC_H

#include "AbstractAppFabric.h"


class WinWidgetsAppFabric : public AbstractAppFabric
{
public:
    WinWidgetsAppFabric();
    std::unique_ptr<GuiInterface>&& createGui() override;
    std::unique_ptr<AbstractWordsDictionary>&& createDictionary() override;
    std::unique_ptr<AbstractWordsFinder>&& createWordsFinder() override;
    ~WinWidgetsAppFabric() override
    {

    }
private:
    std::unique_ptr<GuiInterface> mGui;
    std::unique_ptr<AbstractWordsDictionary> mDict;
    std::unique_ptr<AbstractWordsFinder> mFinder;

};

#endif // WINWIDGETSAPPFABRIC_H
