
#if defined(PLATFORM_WIN32)

#include <windows.h>

BOOL APIENTRY DllMain(HANDLE module, DWORD reason, LPVOID params)
{
    UNREFERENCED_PARAMETER(module);
    UNREFERENCED_PARAMETER(reason);
    UNREFERENCED_PARAMETER(params);
    return TRUE;
}

#endif