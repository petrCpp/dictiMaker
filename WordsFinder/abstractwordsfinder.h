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
    virtual const QMap<QString, uint16_t> &getFoundWords() = 0;
};

#endif // ABSTRACTWORDSFINDER_H
