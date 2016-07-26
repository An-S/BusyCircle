#include "busycircle.h"

/** \brief open a font and puts data into font structure
 *
 * \param
 * \param
 * \return TTF_Font *font, pointer to allocated font structure
 *
 */
TTF_Font *openFont(void){
    TTF_Font *font = TTF_OpenFont("C:\\Windows\\Fonts\\arial.ttf"/*"Millennia.otf"*/, 96);
    if (font){
        return font;
    }
    printSDL_Error("Font loading Error");
    setErrorAndExit(TTF_LOAD_ERR);
    return NULL;
}

/** \brief closes a true type font
 *
 * \param pointer to font structure which should be freed
 * \param
 * \return
 *
 */
void closeFont(TTF_Font *font){
    if (font){
        TTF_CloseFont(font);
    }
}

/** \brief initializes true type font engine from SDL lib
 *
 * \param
 * \param
 * \return
 *
 */
void performTTFInit(void){
    if( -1 == TTF_Init() ) {
        printSDL_Error(__FUNCTION__);
        setErrorAndExit(TTF_INIT_ERR);
    }
}

SDL_Texture *SDL_renderDisc(SDL_Renderer *renderer, TTF_Font *font, uint32_t color){
    static const char const *funcname = __FUNCTION__;

    //assert pointers being not NULL
    assert(font);
    assert(renderer);

//    if (!font){
//        printSDL_Error("font NULL in %s", funcname);
//        setErrorAndExit(OTHER_ERR);
//    }
//    if (!renderer){
//        printSDL_Error("font NULL in %s", funcname);
//        setErrorAndExit(OTHER_ERR);
//    }

    //render unicode symbol representing a circular disc to SDL_Surface
    SDL_Surface *surf = TTF_RenderUNICODE_Solid(font, L"\x25cf", SDL_translateColor(color));
    if (!surf){
        printSDL_Error("Text rendering failed in %s", funcname);
        setErrorAndExit(OTHER_ERR);
    }

    //Convert SDL_Surface to SDL_Texture using renderer
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    if (!texture){
        printSDL_Error("Texture 2 surface err in %s", funcname);
        setErrorAndExit(OTHER_ERR);
    }

    return texture;
 }
