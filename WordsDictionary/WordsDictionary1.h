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
    void setSource(const QString &path) override;
    void setPasword(const QString &password) override;
    bool openSource() override;
    bool loadData() override;
    void appendWords(const QStringList &words) override;
    void removeWord(const QString &word) override;
    bool saveData() override;
    void closeSource() override;
    QMap<QString, QList<ESpeechPart>> words() override;
    void setWords(const QMap<QString, QList<ESpeechPart>> &words) override;
protected:
    const QString mFileFormatVersion = "1434Faad12487331";
    const QString mDictName;
    const QString mDictLanguage;
    QMap<QString, QList<ESpeechPart>> mWords;
    QMap<ESpeechPart, QMap<QString,  QJsonObject>> mWordsBySpeachParts;
    QString mPath;

    static QJsonDocument getJSonDocument(const QString &dictName,
                                         const QString &dictLanguage,
                                         const QString &fileFormatVersion,
                                         const QMap<QString, QList<ESpeechPart>> &mWords);
    static QJsonValue speachPartToJsonValue(ESpeechPart speachPart);
};

#endif // WORDSDICTIONARY1_H
