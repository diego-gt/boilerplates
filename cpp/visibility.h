// Add support for exporting symbols to be used in DLLs
// This is needed because of how MSVC handles default visibility
// Which is not supported by other compilers, this macro handles the cases

#pragma once

#if defined _WIN32 || defined __CYGWIN__
#define _DLL_IMPORT __declspec(dllimport)
#define _DLL_EXPORT __declspec(dllexport)
#define _DLL_LOCAL
#else
#if __GNUC__ >= 4
#define _DLL_IMPORT __attribute__((visibility("default")))
#define _DLL_EXPORT __attribute__((visibility("default")))
#define _DLL_LOCAL __attribute__((visibility("hidden")))
#else
#define _DLL_IMPORT
#define _DLL_EXPORT
#define _DLL_LOCAL
#endif
#endif

// Source: https://gcc.gnu.org/wiki/Visibility
