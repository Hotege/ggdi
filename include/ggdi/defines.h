#if !defined(_GGDI_DEFINES_H_)
#define _GGDI_DEFINES_H_

#if defined(PLATFORM_WIN32)
#if defined(GGDI_DLL)
#define GGDI_API __declspec(dllexport)
#else
#define GGDI_API __declspec(dllimport)
#endif
#else
#define GGDI_API
#endif

#endif