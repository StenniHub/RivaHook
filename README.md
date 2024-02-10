# RivaHook
DLL for injecting text into RivaTuner OSD

RivaHook allows for adding multiple lines of text of the RivaTuner OSD.
Each line of text is to be identified by a unique id, such that the contents can be updated/removed, as well as updates to position and size.

RivaHook currently exposes two main methods:
displayText(id, text, x, y, size);
clearText(id);

x, y and size are optional parameters, but it's strongly recommended to at least specify x/y values to avoid overlaps.

See https://github.com/pseudostripy/DS2S-META for an example on how we use RivaHook as part of a practice tool for Dark Souls II written in C#