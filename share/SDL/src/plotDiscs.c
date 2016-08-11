#include "busycircleInterface.h"

int *slopetable;

//int sintable[] = {
//    #include "sintable.h"
//    /*,
//    /*,
//    #include "sintable.h"*/
//};
//
//int sinpos[DOTS] = {0*DISTANCE,1*DISTANCE,2*DISTANCE,3*DISTANCE,
//                    4*DISTANCE,5*DISTANCE,6*DISTANCE,7*DISTANCE};
//int slopepos[DOTS] = {0*SLOPEDIST, 1*SLOPEDIST, 2*SLOPEDIST, 3*SLOPEDIST,
//                        4*SLOPEDIST, 5*SLOPEDIST, 6*SLOPEDIST, 7*SLOPEDIST};

void initDiscPlotter(size_t len, size_t seqlen, size_t max){
    slopetable = generateSpeedtable(len, seqlen, max);
}

void terminateDiscPlotter(void){
    if (slopetable) destroySpeedtable(slopetable);
}

void plotDiscs(Resources_t *res, drawingObjTargetRect_t *renderRect){
    int sinx,
        siny,
        offsetx = SCREEN_WIDTH/2 - renderRect->w / 2,
        offsety = SCREEN_HEIGHT/2 - renderRect->h / 2;

    for (resetSinIndex(); getSinIndex()<DOTS; incSinIndex()){
        renderRect->x = offsetx+getCurrentSinValue();
        renderRect->y = offsety+getCurrentSinValue();

		updateSin(slopetable);
        SDL_RenderCopy(res->rend, res->tex, 0, renderRect);
    }
}

