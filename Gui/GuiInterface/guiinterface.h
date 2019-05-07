#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

#include <QStringList>
#include "guicommandsinterface.h"
#include <CBasicErrorType.h>
#include <QAbstractItemModel>

class GuiInterface
{
public:
    virtual void setGuiCommandsInterface(GuiCommandsInterface *cmdInterf) = 0;
    virtual void setDictionaryModel(QAbstractItemModel *model) = 0;
    virtual void renderTotalWordsCount(int totalWordsCount) = 0;
    virtual void renderNewFoundWordsCount(int newWordsCount) = 0;
    virtual void renderTotalWords(const QStringList &words) = 0;
    virtual void showErrorMessage(const CBasicErrorType &err) = 0;
    virtual void redrawPercentage(float perc) = 0;
    virtual ~GuiInterface() = 0;
};

#endif // GUIINTERFACE_H
