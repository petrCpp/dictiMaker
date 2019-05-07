#ifndef ABSTRACTAPPFABRIC_H
#define ABSTRACTAPPFABRIC_H

#include <AppFabric/AbstractAppFabric.h>
#include <WordsDictionary/abstractwordsdictionary.h>
#include <WordsFinder/abstractwordsfinder.h>
#include <Gui/GuiInterface/guiinterface.h>
#include <memory>

class AbstractAppFabric
{
public:
    //AbstractAppFabric();
    virtual std::unique_ptr<GuiInterface>&& createGui() = 0;
    virtual std::unique_ptr<AbstractWordsDictionary>&& createDictionary() = 0;
    virtual std::unique_ptr<AbstractWordsFinder>&& createWordsFinder() = 0;
};

#endif // ABSTRACTAPPFABRIC_H
