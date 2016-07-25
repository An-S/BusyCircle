#ifndef BUSYCIRCLE_H_INCLUDED
#define BUSYCIRCLE_H_INCLUDED

#include <stdheaders.h>
#include <SDL.h>
#include <SDL_ttf.h>

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512
#define DOTS 8
#define DISTANCE 12
#define SLOPEDIST 4

//should stay within uint8_t range
enum BUSYCIRC_ERRCODES{NOERR, SDL_INIT_ERR, TTF_INIT_ERR, SDL_WINDOW_ERR, SDL_RENDERER_ERR};

typedef int speedTableElem_t;

speedTableElem_t *generateSpeedtable(size_t len, size_t seqlen, size_t max);
int destroySpeedtable(speedTableElem_t *speedTable);

void performSDLInit(void);
SDL_Window *createSDLWin(const char *name);

void printSDL_Error(const char *errMsg, ...);
void setErrorAndExit(int exitcode);
int getError(void);

#endif // BUSYCIRCLE_H_INCLUDED
