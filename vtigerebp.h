#ifndef VTIGEREBP_H
#define VTIGEREBP_H

#include "vtigerEbp_global.h"
#include <QString>

extern  "C" {
 VTIGEREBPSHARED_EXPORT std::string __stdcall createOrUpdate(QString username, QString id, QString moduleName, QString attributes);
 VTIGEREBPSHARED_EXPORT int __stdcall one(int i);
}

//std::string VTIGEREBPSHARED_EXPORT createOrUpdate(QString username, QString id, QString moduleName, QString attributes);

/*
class VTIGEREBPSHARED_EXPORT vtigerEbp
{
public:
    std::string vtigerEbp(QString username, QString id, QString moduleName, QString attributes);
    std::string createOrUpdate(QString username, QString id, QString moduleName, QString attributes);
};
*/
#endif // VTIGEREBP_H
