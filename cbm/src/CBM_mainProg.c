#include "busycircleInterface.h"

int mainProg(void){
    static drawingObjTargetRect_t renderRect;
    Resources_t *res = NULL;

    printf("def spr rect\n");
    getVICSpriteRect(&renderRect);
    printf("init res\n");
    res = initResources();
    printf("plotdiscs!");
    putchar(147);//clears screen according to cbm control characters
    while(true){
        plotDiscs(res, &renderRect);
    }
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
    freeResources(res);
    return 0;

}


