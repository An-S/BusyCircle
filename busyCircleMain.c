
#include "busycircle.h"



SDL_Window *window;
SDL_Renderer *renderer;
TTF_Font *font;
SDL_Surface *surf;
SDL_Texture *texture;


void freeResources(void){
    if (window){
        SDL_DestroyWindow(window);
    }
    if (renderer){
        SDL_DestroyRenderer(renderer);
    }
    if (texture){
        SDL_DestroyTexture(texture);
    }

    terminateDiscPlotter();

    SDL_Quit();
    if (getError()){
        fprintf(stderr, "Press enter to go on.");
        getchar();
    }
}

int APIENTRY WinMain(HINSTANCE inst,HINSTANCE previnst,LPSTR lpCmdLine,int nCmdShow) {

    SDL_Rect renderRect;

    atexit(freeResources);
    initDiscPlotter(256, 16, 4);

    //following init functions exit when error occurs
    performSDLInit();
    performTTFInit();
    font = openFont();
    window = createSDLWin("Busy circle!");
    renderer = SDL_getRenderer(window);

    //SDL_renderDisc(renderer, font, textColor);
    texture = SDL_renderDisc(renderer, font, 0x00ffffff);
    SDL_QueryTexture(texture, 0, 0, &(renderRect.w), &(renderRect.h));
    closeFont(font);

    while(!SDL_checkQuitEvent()) {

        SDL_RenderClear(renderer);
        plotDiscs(renderer, texture, renderRect);
        SDL_RenderPresent(renderer);
        //SDL_Delay(1000/70);
    }

    return 0;
}
