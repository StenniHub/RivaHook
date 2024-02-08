// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the RIVAHOOK_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// RIVAHOOK_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RIVAHOOK_EXPORTS
#define RIVAHOOK_API __declspec(dllexport)
#else
#define RIVAHOOK_API __declspec(dllimport)
#endif

extern "C" RIVAHOOK_API int displayText(const char* id, const char* text, int x, int y, int size);
extern "C" RIVAHOOK_API int clearText(const char* id);
