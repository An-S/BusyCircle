#ifndef BUSYCIRCLEINFERFACE_H_INCLUDED
#define BUSYCIRCLEINFERFACE_H_INCLUDED

#include <stdheaders.h>
#include <cmacros.h>

#define SDL_MAIN_HANDLED

#ifdef WINDOWS_TARGET
    #include "busycircle_SDL.h"
#endif // WINDOWS_TARGET

#ifdef LINUX_TARGET
	#include "busycircle_SDL.h"
#endif // LINUX_TARGET

#ifdef CBM_TARGET
    #include "busycircle_CBM.h"
#endif // TARGET_OS

#include "busycircle.h"


#endif // BUSYCIRCLEINFERFACE_H_INCLUDED

