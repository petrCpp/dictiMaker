#ifndef GUICOMMANDSINTERFACE_H
#define GUICOMMANDSINTERFACE_H

#include <QString>

enum EWordDictSource
{
    file,
    mysqlDb,
};


class GuiCommandsInterface
{
public:
    //GuiCommandsInterface();
    virtual void openTextFileToFindWords(const QString & fileName)=0;
    virtual void setDictSource(const QString &source) = 0;
    virtual void saveDictionary(EWordDictSource source)=0;
    virtual void loadDictionary(EWordDictSource source)=0;
    virtual void closeApp()=0;
};

#endif // GUICOMMANDSINTERFACE_H
