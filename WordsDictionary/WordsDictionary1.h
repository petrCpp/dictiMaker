#ifndef WORDSDICTIONARY1_H
#define WORDSDICTIONARY1_H

#include "abstractwordsdictionary.h"
#include <QMap>
#include <QList>
#include <QJsonObject>
#include <QJsonDocument>


class WordsDictionary1 : public AbstractWordsDictionary
{
public:
    WordsDictionary1();
    ~WordsDictionary1() override
    {
        ;
    }
    void setSource(const QString &path) override;
    void setDictLanguage(const QString &lang) override;
    void setDictName(const QString &dictrName) override;
    void setPasword(const QString &password) override;
    QString getDictLanguage() override;
    QString getDictName() override;
    bool openSource() override;
    bool loadData() override;
    void appendWords(const QStringList &words) override;
    void removeWord(const QString &word) override;
    bool saveData() override;
    void closeSource() override;
    QMap<QString, QList<ESpeechPart>> words() override;
    void setWords(const QMap<QString, QList<ESpeechPart>> &words) override;
protected:
    QString mFileFormatVersion = "1434Faad12487331";
    QString mDictName;
    QString mDictLanguage;
    QMap<QString, QList<ESpeechPart>> mWords;
    QMap<ESpeechPart, QMap<QString,  QJsonObject>> mWordsBySpeachParts;
    QString mPath;

    static QJsonDocument getJSonDocument(const QString &dictName,
                                         const QString &dictLanguage,
                                         const QString &fileFormatVersion,
                                         const QMap<QString, QList<ESpeechPart>> &mWords);
    static QJsonValue speachPartToJsonValue(ESpeechPart speachPart);
private:
    static QString objValueToString(const QJsonObject &obj, const QString &key);
    static ESpeechPart jsonValueToSpeachPart(const QJsonValue &val);
    static void getDictFromJSonDocument(const QJsonDocument &doc, QString &dictName, QString &dictLanguage, QString &fileFormatVersion, QMap<QString, QList<ESpeechPart> > &words);
};

#endif // WORDSDICTIONARY1_H
