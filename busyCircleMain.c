
#include "busycircle.h"



SDL_Window *window;
SDL_Renderer *renderer;
TTF_Font *font;
SDL_Surface *surf;
SDL_Texture *texture;
int *slopetable;

int sintable[] = {
    #include "sintable.h"
    /*,
    #include "sintable.h"*/
};

int sinpos[DOTS] = {0*DISTANCE,1*DISTANCE,2*DISTANCE,3*DISTANCE,
                    4*DISTANCE,5*DISTANCE,6*DISTANCE,7*DISTANCE};
int slopepos[DOTS] = {0*SLOPEDIST, 1*SLOPEDIST, 2*SLOPEDIST, 3*SLOPEDIST,
                        4*SLOPEDIST, 5*SLOPEDIST, 6*SLOPEDIST, 7*SLOPEDIST};

TTF_Font *initFont(void){
    TTF_Font *font = TTF_OpenFont("C:\\Windows\\Fonts\\arial.ttf"/*"Millennia.otf"*/, 96);
    return font;
}

void freeResources(void){
    TTF_CloseFont(font);

    if (window){
        SDL_DestroyWindow(window);
    }
    if (renderer){
        SDL_DestroyRenderer(renderer);
    }
    if (texture){
        SDL_DestroyTexture(texture);
    }
    destroySpeedtable(slopetable);

    SDL_Quit();
    if (getError()){
        fprintf(stderr, "Press enter to go on.");
        getchar();
    }
}

int APIENTRY WinMain(HINSTANCE inst,HINSTANCE previnst,LPSTR lpCmdLine,int nCmdShow) {

    SDL_Rect renderRect;
    SDL_Color textColor = {255,255,255,255};

    bool done = false;
    int i;
    atexit(freeResources);
    slopetable = generateSpeedtable(256, 16, 4);

    performSDLInit();

    if( -1 == TTF_Init() ) {
        fprintf(stderr, "TTF_Init() Error: %s\n", TTF_GetError());
        return 3;
    }
    font = initFont();
    if(!font){
        fprintf(stderr, "Font loading Error: %s\n", TTF_GetError());
        return 2;
    }
    window = createSDLWin("Busy circle!");

    if(!window){
        fprintf(stderr, "SDL_CreateWindow() Error: %s\n", SDL_GetError());
        //TTF_Quit();
        return 5;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(!renderer) {
        fprintf(stderr, "SDL_CreateRenderer() Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        //TTF_Quit();
        return 6;
    }

    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    surf = TTF_RenderUNICODE_Solid(font, L"\x25cf", textColor);
    texture = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);

    SDL_QueryTexture(texture, 0, 0, &(renderRect.w), &(renderRect.h));


    while(!done) {
    SDL_Event event;


        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = 1;
            }
            else if(event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                done = 1;
            }
            }
        }
        SDL_RenderClear(renderer);
        for (i = 0; i<DOTS; ++i){
            //SDL_RenderDrawPoint(renderer, 100+sintable[sinpos[i]], 100+sintable[sinpos[i]+64]);
            renderRect.x = (SCREEN_WIDTH/2)+sintable[sinpos[i]]-renderRect.w/2;
            renderRect.y = (SCREEN_HEIGHT/2)+sintable[sinpos[i]+64]-renderRect.h/2;

            sinpos[i] = (sinpos[i]+slopetable[slopepos[i]])%256;
            slopepos[i] = (slopepos[i]+1)%256;
            SDL_RenderCopy(renderer, texture, 0, &renderRect);
        }
        SDL_RenderPresent(renderer);
        //SDL_Delay(1000/70);
    }

    return 0;
}
