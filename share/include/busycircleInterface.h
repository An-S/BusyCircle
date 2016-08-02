#ifndef BUSYCIRCLEINFERFACE_H_INCLUDED
#define BUSYCIRCLEINFERFACE_H_INCLUDED

#include "busycircle.h"

#ifdef WINDOWS_TARGET || LINUX_TARGET
    #include "busycircle_SDL.h"

#else
    #include "busycircle_CBM.h"

#endif // TARGET_OS

#endif // BUSYCIRCLEINFERFACE_H_INCLUDED

