#include "WordsDictionary1.h"
#include <QJsonArray>
#include <QFile>

WordsDictionary1::WordsDictionary1()
{

}

void WordsDictionary1::setSource(const QString &path)
{
    mPath = path;
}

void WordsDictionary1::setPasword(const QString &password)
{
    Q_UNUSED(password);
}

bool WordsDictionary1::openSource()
{
    return false;
}

bool WordsDictionary1::loadData()
{
    ?????????????
    return false;
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
    }
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
