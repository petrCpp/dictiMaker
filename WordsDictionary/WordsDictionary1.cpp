#include "WordsDictionary1.h"
#include <QJsonArray>
#include <QFile>
#include <QLatin1String>

WordsDictionary1::WordsDictionary1()
{

}


void WordsDictionary1::setSource(const QString &path)
{
    mPath = path;
}

void WordsDictionary1::setDictLanguage(const QString &lang)
{
    mDictLanguage = lang;
}

void WordsDictionary1::setDictName(const QString &dictrName)
{
    mDictName = dictrName;
}

void WordsDictionary1::setPasword(const QString &password)
{
    Q_UNUSED(password);
}

QString WordsDictionary1::getDictLanguage()
{
    return mDictLanguage;
}

QString WordsDictionary1::getDictName()
{
    return mDictName;
}

bool WordsDictionary1::openSource()
{
    return false;
}

bool WordsDictionary1::loadData()
{
    QFile file(mPath);
    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QByteArray arr = file.read(100000000);
    file.close();
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(arr, &err);
    if(err.error != QJsonParseError::NoError)
    {
        return false;
    }
    getDictFromJSonDocument(doc, mDictName, mDictLanguage,
                                            mFileFormatVersion,
                                            mWords);
    return true;
}

QString WordsDictionary1::objValueToString(const QJsonObject &obj,
                                           const QString &key)
{
    QString res;
    QJsonObject::const_iterator it;
    it = obj.find(key);
    if(it != obj.end())
    {
        QJsonValue val = *it;
        res = val.toString();
    }
    return res;
}




void WordsDictionary1::getDictFromJSonDocument(const QJsonDocument &doc,
                                                QString &dictName,
                                                QString &dictLanguage,
                                                QString &fileFormatVersion,
                                                QMap<QString, QList<ESpeechPart> > &words)
{
    QJsonObject obj = doc.object();
    dictName = objValueToString(obj, "dictName");
    dictLanguage = objValueToString(obj, "dictLanguage");
    fileFormatVersion = objValueToString(obj, "fileFormatVersion");

    QJsonObject::iterator it;
    it = obj.find("words");
    QJsonObject wordsObj;
    if(it != obj.end())
    {
        QJsonValue val = *it;
        wordsObj = val.toObject();
    }
    words.clear();
    for(it = wordsObj.begin(); it != wordsObj.end() ; ++it) {
        QJsonValue value = it.value();
        QJsonArray jsonArr;
        if(value.isArray())
        {
            jsonArr = value.toArray();
        }
        QList<ESpeechPart> lst;
        for(int i=0; i<jsonArr.size(); ++i)
        {
            lst.append(jsonValueToSpeachPart(jsonArr[i].toString()));
        }
        words[it.key()] = lst;
    }
}

void WordsDictionary1::appendWords(const QStringList &words)
{
    for(const QString &word: words)
    {
        if(!mWords.contains(word))
        {
            mWords[word] = QList<ESpeechPart>();
        }
    }
}

void WordsDictionary1::removeWord(const QString &word)
{
    if(mWords.contains(word))
        mWords.remove(word);
}

bool WordsDictionary1::saveData()
{
    QJsonDocument doc = WordsDictionary1::getJSonDocument(mDictName,
                                                    mDictLanguage,
                                                    mFileFormatVersion,
                                                    mWords);
    QFile file(mPath);
    if(!file.open(QIODevice::WriteOnly))
    {
        return false;
    }
    file.write(doc.toJson());
    file.flush();
    file.close();
    return true;
}

void WordsDictionary1::closeSource()
{

}

QMap<QString, QList<ESpeechPart>> WordsDictionary1::words()
{
    return mWords;
}

void WordsDictionary1::setWords(const QMap<QString, QList<ESpeechPart> > &words)
{
    Q_UNUSED(words);
}

QJsonValue  WordsDictionary1::speachPartToJsonValue(ESpeechPart speachPart)
{
    switch(speachPart)
    {
    case ESpeechPart::noun: return QJsonValue("noun");
    case ESpeechPart::adjective: return QJsonValue("adjective");
    case ESpeechPart::shortAdjective: return QJsonValue("shortAdjective");
    case ESpeechPart::numeral: return QJsonValue("numeral");
    case ESpeechPart::pronoun: return QJsonValue("pronoun");
    case ESpeechPart::verb: return QJsonValue("verb");
    case ESpeechPart::adverb: return QJsonValue("adverb");
    case ESpeechPart::preposition: return QJsonValue("preposition");
    case ESpeechPart::conjunction: return QJsonValue("conjunction");
    case ESpeechPart::particle: return QJsonValue("particle");
    case ESpeechPart::interjection: return QJsonValue("interjection");
    case ESpeechPart::nonWord: return QJsonValue("nonWord");
    case ESpeechPart::foreignWord: return QJsonValue("foreignWord");
    case ESpeechPart::unknown: return QJsonValue("unknown");
    }
    return QJsonValue("unknown");
}


ESpeechPart  WordsDictionary1::jsonValueToSpeachPart(const QJsonValue &val)
{
    if(!val.isString())
    {
        return ESpeechPart::unknown;
    }
    const QString str = val.toString();

    const QMap<QString, ESpeechPart> vals
    {
        {"noun",ESpeechPart::noun},
        {"adjective",ESpeechPart::adjective},
        {"shortAdjective",ESpeechPart::shortAdjective},
        {"numeral",ESpeechPart::numeral},
        {"pronoun",ESpeechPart::pronoun},
        {"verb",ESpeechPart::verb},
        {"adverb",ESpeechPart::adverb},
        {"preposition",ESpeechPart::preposition},
        {"conjunction",ESpeechPart::conjunction},
        {"particle",ESpeechPart::particle},
        {"interjection",ESpeechPart::interjection},
        {"nonWord",ESpeechPart::nonWord},
        {"foreignWord",ESpeechPart::foreignWord},
        {"unknown",ESpeechPart::unknown},
    };
    if(vals.contains(str))
    {
        return vals[str];
    }
    return ESpeechPart::unknown;
}



QJsonDocument WordsDictionary1::getJSonDocument(const QString &dictName,
                                                const QString &dictLanguage,
                                                const QString &fileFormatVersion,
                                                const QMap<QString, QList<ESpeechPart> > &mWords)
{
    QJsonDocument doc;
    QJsonObject title;
    title.insert("dictName", QJsonValue(dictName));
    title.insert("dictLanguage", QJsonValue(dictLanguage));
    title.insert("fileFormatVersion", QJsonValue(fileFormatVersion));

    QJsonObject words;
    QMap<QString, QList<ESpeechPart> >::const_iterator it;
    for(it = mWords.constBegin(); it != mWords.constEnd() ; ++it) {
        const QList<ESpeechPart> &val = it.value();
        QJsonArray valueArr;
        for(int i=0; i<val.size(); i++)
        {
            valueArr.append(speachPartToJsonValue(val[i]));
        }
        words.insert(it.key(), valueArr);
    }
    title.insert("words", QJsonValue(words));
    doc.setObject(title);
    return doc;
}
