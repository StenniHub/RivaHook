// RivaHook.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "OSD.h"
#include "RivaHook.h"

int displayText(const char* id, const char* text, int x=0, int y=0, int size=100)
{
	CHAR formatted[256];
	wsprintfA(formatted, "<P=%d,%d><S=%d>%s", x, y, size, text);
	UpdateOSD(formatted, id);

	// If we instead removed the placeholder, text would appear above the FPS counter
	// Considered making this configurable behavior, but would cause conflicts if multiple apps use the DLL with different configurations
	refreshPlaceholder();

    return 0;
}

// Placeholder is never cleared anymore to ensure original OSD stays on top
// Does not appear to have side effects apart from permanently taking up one slot
int clearText(const char* id) {
	ReleaseOSD(id);
    return 0;
}

void refreshPlaceholder() {
	// Needs to be called at the end of each call to displayText to fix the displacement of the FPS counter
	// FPS counter will still be shifted a tiny bit, but negative position values aren't helping to shift it back
	UpdateOSD("<P=0,0><S=100>", PLACEHOLDER_NAME);
}

int test() {
	displayText("OSD_ID_1", "YOUR BING SEARCH IS OUT OF DATE", 0, 15, 100);
	displayText("OSD_ID_2", "I LOVE DARK SOULS 2 BatChest", 0, 25, 100);
	clearText("OSD_ID_2");  // Tests that removing one of the lines still retains the original OSD on top
	return 0;
}
