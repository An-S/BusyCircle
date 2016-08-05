
#include "busycircle.h"
#include "busycircle_SDL.h"


int main(int argc, char *argv[])
 {
    SDL_Rect renderRect;
    SDL_Renderer *renderer;
    SDL_Texture *texture;

    //init resources registers exit handler
    initResources();
    renderer = getRenderer();
    texture = getTexture();

    SDL_QueryTexture(texture, 0, 0, &(renderRect.w), &(renderRect.h));

    while(!SDL_checkQuitEvent()) {

        SDL_RenderClear(renderer);
        plotDiscs(renderer, texture, renderRect);
        SDL_RenderPresent(renderer);
        //SDL_Delay(1000/70);
    }

    return 0;
}

