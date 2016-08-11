#include "busycircleInterface.h"

int mainProg(void){
    SDL_Rect renderRect;
    Resources_t *res;
    //SDL_Renderer *renderer;
    //SDL_Texture *texture;

    res = initResources();
    //renderer = getRenderer();
    //texture = getTexture();

    SDL_QueryTexture(res->tex, 0, 0, &(renderRect.w), &(renderRect.h));

    while(!SDL_checkQuitEvent()) {

        SDL_RenderClear(res->rend);
        plotDiscs(res, &renderRect);
        SDL_RenderPresent(res->rend);
        //SDL_Delay(1000/70);
    }
	freeResources(res);
    return 0;
}

