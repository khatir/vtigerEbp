#ifndef VTIGEREBP_GLOBAL_H
#define VTIGEREBP_GLOBAL_H
#include <QtCore/qglobal.h>

#if defined(VTIGEREBP_LIBRARY)
#  define VTIGEREBPSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VTIGEREBPSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // VTIGEREBP_GLOBAL_H