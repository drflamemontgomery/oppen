#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(OPPENAPI)
#if defined(_WIN32) && defined(_OPPEN_BUILD_DLL)
  /* We are building OPPEN as a Win32 DLL */
#define OPPENAPI __declspec(dllexport)
#elif defined(_WIN32) && defined(OPPEN_DLL)
  /* We are calling OPPEN as a Win32 DLL */
#define OPPENAPI __declspec(dllimport)
#elif defined(__GNUC__) && defined(_OPPEN_BUILD_DLL)
  /* We are building OPPEN as a shared / dynamic library */
#define OPPENAPI __attribute__((visibility("default")))
#else
  /* We are building or calling OPPEN as a static library */
#define OPPENAPI
#endif
#endif
  
#include "graphics/window.h"
  

#ifdef __cplusplus
}
#endif
