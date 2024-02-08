// RivaHook.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "OSD.h"
#include "RivaHook.h"

#define Map1 "RTSS_Overlay"
#define Map2 "RTSS_Placeholder"  // TODO: Remove?

CHAR osd_text[256] = "YOUR BING SEARCH IS OUT OF DATE";

int displayText(void)
{
	int x = 0, y = 15, size = 100;
	CHAR format[256];

	wsprintfA(format, "<P=%d,%d><S=%d>%s", x, y, size, osd_text);
	UpdateOSD(format, Map1);
	UpdateOSD("<P=0,0><S=100>", Map2);  // TODO: What does this do?

    return 0;
}

int clearText(void) {
	ReleaseOSD(Map1);
	ReleaseOSD(Map2);
    return 0;
}
