#ifndef BUSYCIRCLEINFERFACE_H_INCLUDED
#define BUSYCIRCLEINFERFACE_H_INCLUDED

#include "busycircle.h"

#ifdef WINDOWS_TARGET
    #include "busycircle_SDL.h"
#endif // WINDOWS_TARGET

#ifdef LINUX_TARGET
	#include "busycircle_SDL.h"
#endif // LINUX_TARGET

#ifdef CBM_TARGET
    #include "busycircle_CBM.h"
#endif // TARGET_OS

#endif // BUSYCIRCLEINFERFACE_H_INCLUDED

