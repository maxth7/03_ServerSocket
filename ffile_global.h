#ifndef FFILE_GLOBAL_H
#define FFILE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FFILE_LIBRARY)
#define FFILE_EXPORT Q_DECL_EXPORT
#else
#define FFILE_EXPORT Q_DECL_IMPORT
#endif

#endif // FFILE_GLOBAL_H
