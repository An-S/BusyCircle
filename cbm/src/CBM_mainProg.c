#include "busycircleInterface.h"

int mainProg(void){
    drawingObjTargetRect_t *renderRect;
    Renderer_t *renderer;
    Texture_t *texture;

    printf("def spr rect\n");
    getVICSpriteRect(renderRect);
    printf("init res\n");
    initResources();
    printf("plotdiscs!");
    plotDiscs(renderer, texture, renderRect);
    /*renderer = getRenderer();
    texture = getTexture();

    SDL_QueryTexture(texture, 0, 0, &(renderRect.w), &(renderRect.h));

    while(!SDL_checkQuitEvent()) {

        SDL_RenderClear(renderer);
        plotDiscs(renderer, texture, renderRect);
        SDL_RenderPresent(renderer);
        //SDL_Delay(1000/70);
    }
*/
    return 0;

}


