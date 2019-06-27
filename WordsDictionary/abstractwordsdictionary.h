#ifndef ABSTRACTWORDSDICTIONARY_H
#define ABSTRACTWORDSDICTIONARY_H

#include <QStringList>
#include <QMap>
#include <QString>

enum class ESpeechPart: uint8_t
{
    noun,
    adjective,
    shortAdjective,
    numeral,
    pronoun,
    verb,
    adverb,
    preposition,
    conjunction,
    particle,
    interjection,
    nonWord,        // is not word
    foreignWord,
    unknown,
    partsCount
};



class AbstractWordsDictionary
{
public:
    //AbstractWordsDictionary();
    virtual void setSource(const QString &path) = 0;
    virtual void setDictLanguage(const QString &lang) = 0;
    virtual void setDictName(const QString &dictrName) = 0;
    virtual void setPasword(const QString &password) = 0;
    virtual QString getDictLanguage() = 0;
    virtual QString getDictName() = 0;
    virtual bool openSource() = 0;
    virtual bool loadData() = 0;
    virtual void appendWords(const QStringList &words) = 0;
    virtual void removeWord(const QString &word) = 0;
    virtual bool saveData() = 0;
    virtual void closeSource() = 0;
    virtual QMap<QString, QList<ESpeechPart>> words() = 0;
    virtual void setWords(const QMap<QString, QList<ESpeechPart>> &words) = 0;
    virtual QMap<ESpeechPart, QString> getSpeachPartsNames() const =0 ;
    virtual ~AbstractWordsDictionary() = 0;
};

#endif // ABSTRACTWORDSDICTIONARY_H
