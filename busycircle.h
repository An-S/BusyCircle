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
enum BUSYCIRC_ERRCODES{NOERR, SDL_INIT_ERR, TTF_INIT_ERR, TTF_LOAD_ERR, SDL_WINDOW_ERR, SDL_DRAWDISC_ERR, SDL_RENDERER_ERR, OTHER_ERR};

typedef int speedTableElem_t;

speedTableElem_t *generateSpeedtable(size_t len, size_t seqlen, size_t max);
int destroySpeedtable(speedTableElem_t *speedTable);

void performSDLInit(void);
SDL_Window *createSDLWin(const char *name);
SDL_Renderer *SDL_getRenderer(SDL_Window *window);
bool SDL_checkQuitEvent(void);
SDL_Color SDL_translateColor(uint32_t int_color);
SDL_Texture *SDL_renderDisc(SDL_Renderer *renderer, TTF_Font *font, uint32_t color);

void initResources(void);
void freeResources(void);
SDL_Renderer *getRenderer(void);
SDL_Texture *getTexture(void);

void performTTFInit(void);
TTF_Font *openFont(void);
void closeFont(TTF_Font *fnt);

void printSDL_Error(const char *errMsg, ...);
void setErrorAndExit(int exitcode);
int getError(void);

void initDiscPlotter(size_t len, size_t seqlen, size_t max);
void terminateDiscPlotter(void);
void plotDiscs(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect renderRect);

#endif // BUSYCIRCLE_H_INCLUDED
