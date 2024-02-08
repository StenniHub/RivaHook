// RivaHook.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "OSD.h"
#include "RivaHook.h"

#define PLACEHOLDER_NAME "OSD_PLACEHOLDER"

int displayText(const char* id, const char* text, int x, int y, int size)
{
	CHAR formatted[256];
	wsprintfA(formatted, "<P=%d,%d><S=%d>%s", x, y, size, text);
	UpdateOSD(formatted, id);

	// Needs to be called at the end to not displace the FPS counter
	// Still shifts the FPS counter a tiny bit, but negative position values aren't helping
	UpdateOSD("<P=0,0><S=100>", PLACEHOLDER_NAME);

    return 0;
}

int clearText(const char* id) {
	ReleaseOSD(id);
	ReleaseOSD(PLACEHOLDER_NAME);
    return 0;
}
