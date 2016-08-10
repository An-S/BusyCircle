#include "busycircleInterface.h"

int sintable[] = {
    #include "sintable.h"
    /*,
    #include "sintable.h"*/
};

uint8_t sinpos[DOTS] = {0*DISTANCE,1*DISTANCE,2*DISTANCE,3*DISTANCE,
                    4*DISTANCE,5*DISTANCE,6*DISTANCE,7*DISTANCE};
uint8_t slopepos[DOTS] = {0*SLOPEDIST, 1*SLOPEDIST, 2*SLOPEDIST, 3*SLOPEDIST,
                        4*SLOPEDIST, 5*SLOPEDIST, 6*SLOPEDIST, 7*SLOPEDIST};

int getSin(uint8_t index){
    return sintable[sinpos[index]];
}

int updateSin(uint8_t i){
    return sinpos[i]= (sinpos[i]+slopetable[slopepos_current])%256
}
int updateSlop(uint8_t i){
    return slopepos[i] (slopepos_current+1)%256;
}

