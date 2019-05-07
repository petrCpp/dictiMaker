#ifndef CBASIC_ERROR_TYPE_H
#define CBASIC_ERROR_TYPE_H

#include <QString>

class CBasicErrorType
{
public:
    virtual bool errorOccure() const { return true;}
    virtual int errorCode() const { return -1;}
    virtual QString errorSource() const { return "";} // Возвращает имя класса, который
                                            // сгенерировал ошибку
    virtual QString errorDescription() const { return "";}
    virtual QString errorResolve() const { return "";}
};

#endif // CBASIC_ERROR_TYPE_H
