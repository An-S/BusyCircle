#include "busycircle.h"
#include "busycircle_SDL.h"

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

void initDiscPlotter(size_t len, size_t seqlen, size_t max){
    slopetable = generateSpeedtable(256, 16, 4);
}

void terminateDiscPlotter(void){
    if (slopetable) destroySpeedtable(slopetable);
}

void plotDiscs(Renderer_t *renderer, Texture_t *texture, Target_t renderRect){
    size_t i;
    for (i = 0; i<DOTS; ++i){
        renderRect.x = (SCREEN_WIDTH/2)+sintable[sinpos[i]]-renderRect.w/2;
        renderRect.y = (SCREEN_HEIGHT/2)+sintable[sinpos[i]+64]-renderRect.h/2;

        sinpos[i] = (sinpos[i]+slopetable[slopepos[i]])%256;
        slopepos[i] = (slopepos[i]+1)%256;
        SDL_RenderCopy(renderer, texture, 0, &renderRect);
    }
}


