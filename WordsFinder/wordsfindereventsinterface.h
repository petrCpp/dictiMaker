#ifndef WORDSFINDEREVENTSINTERFACE_H
#define WORDSFINDEREVENTSINTERFACE_H

enum class EWordsFinderResult
{
    fileNotFoundError,
    unableOpenFileError,
    fileUnknownFormatError,
    succes
};


class WordsFinderEventsInterface
{
public:
    virtual void percentegesCompleted(float perc) = 0;
    virtual void completed(EWordsFinderResult result) = 0;
};

#endif // WORDSFINDEREVENTSINTERFACE_H
