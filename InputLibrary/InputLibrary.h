#pragma once

#define LIBNAME INPUT
#define LIBNAME_VER_MAJOR 1
#define LIBNAME_VER_MINOR 0

// Platform Defines
// Note: Only Win32 is currently implemented
//#if defined(__ANDROID__) || defined(ANDROID)
//#define LIBNAME_PLATFORM_ANDROID
//
//#elif defined(__linux) || defined(__linux) || defined(linux) || defined(LINUX)
//#define LIBNAME_PLATFORM_LINUX

#if defined(_WIN32) || defined(__WIN32__) || defined(_MSC_VER)
#define LIBNAME_PLATFORM_WINDOWS

//#elif defined(__APPLE__)
//#if TARGET_OS_IPHONE
//#define LIBNAME_PLATFORM_IOS
//#elif TARGET_OS_MAC
//#define LIBNAME_PLATFORM_MAC
//#else
//#error LIBNAME: Unknown/unsupported Apple platform
//#endif

#else
#error LIBNAME: Unknown/unsupported platform
#endif

//// Windows Includes
//#if defined(LIBNAME_PLATFORM_WINDOWS)
//#include <stdlib.h>
//#endif

#include "Keyboard.h"
#include "Mouse.h"