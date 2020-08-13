//
// Created by yretenai on 2020-08-08.
//

#ifndef LIBOOZ_EXPORT_H
#define LIBOOZ_EXPORT_H

#ifdef _WIN32
#include "autogen/export_win32.h"
#else
#include "autogen/export_clang.h"
#endif

#endif //LIBOOZ_EXPORT_H
