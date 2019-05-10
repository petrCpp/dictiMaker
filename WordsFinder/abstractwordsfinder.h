#ifndef ABSTRACTWORDSFINDER_H
#define ABSTRACTWORDSFINDER_H

#include "wordsfindereventsinterface.h"
#include <QString>
#include <CBasicErrorType.h>

class AbstractWordsFinder
{
public:
    virtual void setWordsFinderEvents(WordsFinderEventsInterface *events) = 0;
    //virtual void setDocumentPath(const QString &fileName) = 0;
    virtual bool startFindWords(const QString &fileName/*, CBasicErrorType &err*/) = 0;
    virtual QStringList getFoundWords() = 0;
    virtual ~AbstractWordsFinder() = 0;
};

#endif // ABSTRACTWORDSFINDER_H
