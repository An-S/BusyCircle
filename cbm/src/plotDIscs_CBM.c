#include "busycircleInterface.h"

speedTableElem_t *slopetable;

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
    slopetable = generateSpeedtable(len, seqlen, max);
}

void terminateDiscPlotter(void){
    if (slopetable) destroySpeedtable(slopetable);
}

/*
CBM_discRenderer(Renderer_t *renderer, Texture_t *texture, drawingObjTargetRect_t *renderRect){
    int x = (SCREEN_WIDTH/2)+sintable[sinpos[i]]-renderRect->w/2;
    int y = (SCREEN_HEIGHT/2)+sintable[sinpos[i]+64]-renderRect->h/2;
    getDrawingPosition(x,y,renderRect);

}*/

void plotDiscs(Renderer_t *renderer, Texture_t *texture, drawingObjTargetRect_t *renderRect){
    static uint8_t i, ix2;
    int sinx, siny;
    VIC.spr_hi_x = 0;

    for (i = 0, ix2=0; i<DOTS; ++i,ix2+=2){
        sinx = (SCREEN_WIDTH/2)+sintable[sinpos[i]]-renderRect->w/2;
        siny = (SCREEN_HEIGHT/2)+sintable[sinpos[i]+64]-renderRect->h/2;
        sinx/=2;
        siny/=2;

        renderRect->x = sinx; //(SCREEN_WIDTH/2)+sintable[sinpos[i]]-renderRect->w/2;
        asm("ldx %v", ix2);
        asm("sta %w,x", 0xd000);
        __AX__ =  renderRect->y = (SCREEN_HEIGHT/2)+sintable[sinpos[i]+64]-renderRect->h/2;
        asm("ldx %v", ix2);
        asm("sta %w,x", 0xd001);

        sinpos[i] = (sinpos[i]+slopetable[slopepos[i]])%256;
        slopepos[i] = (slopepos[i]+1)%256;

        if ((renderRect->x>>8) > 0) VIC.spr_hi_x |= powerof2table[i];
        //SDL_RenderCopy(renderer, texture, 0, &renderRect);
    }
}


