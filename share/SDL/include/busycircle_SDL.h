#ifndef BUSYCIRCLE_SDL_H_INCLUDED
#define BUSYCIRCLE_SDL_H_INCLUDED

#include <stdheaders.h>
#include <MCLib.h>
#include <SDL.h>
#include <SDL_ttf.h>

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512

typedef size_t drawingObjDim_t;

typedef SDL_Rect drawingObjTargetRect_t;

typedef SDL_Renderer Renderer_t;
typedef SDL_Texture Texture_t;

//should stay within uint8_t range
enum BUSYCIRC_ERRCODES{NOERR, SDL_INIT_ERR, TTF_INIT_ERR, TTF_LOAD_ERR, SDL_WINDOW_ERR, SDL_DRAWDISC_ERR, SDL_RENDERER_ERR, OTHER_ERR};
void performSDLInit(void);
SDL_Window *createSDLWin(const char *name);
SDL_Renderer *SDL_getRenderer(SDL_Window *window);
bool SDL_checkQuitEvent(void);
SDL_Color SDL_translateColor(uint32_t int_color);
SDL_Texture *SDL_renderDisc(SDL_Renderer *renderer, TTF_Font *font, uint32_t color);

SDL_Renderer *getRenderer(void);
SDL_Texture *getTexture(void);

void performTTFInit(void);
TTF_Font *openFont(void);
void closeFont(TTF_Font *fnt);

void printSDL_Error(const char *errMsg, ...);
//void plotDiscs(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect renderRect);


#endif // BUSYCIRCLE_SDL_H_INCLUDED
