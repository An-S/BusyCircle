#include "busycircleInterface.h"

#define SINMAX 200

enum getSinStates_t{GETXSIN, GETYSIN,
int sintable[] = {
    #include "sintable.h"
    /*,
    #include "sintable.h"*/
};

uint8_t sinpos[DOTS] =  	{
								0*DISTANCE,1*DISTANCE,2*DISTANCE,3*DISTANCE,
								4*DISTANCE,5*DISTANCE,6*DISTANCE,7*DISTANCE
							};

uint8_t slopepos[DOTS] = 	{
								0*SLOPEDIST, 1*SLOPEDIST, 2*SLOPEDIST, 3*SLOPEDIST,
								4*SLOPEDIST, 5*SLOPEDIST, 6*SLOPEDIST, 7*SLOPEDIST
							};

int sinpos_current, slopepos_current;

void resetSinIndex(void){
	index = 0;
}

uint8_t getSinIndex(void){
	return index;
}

bool testSinIndexRange(uint8_t max){
	return index<max;
}

void incSinIndex(void){
	++index;
}

int getCurrentSinValue(void){
	static uint8_t state
	sinpos_current = sinpos[index];
	slopepos_current = slopepos[index];
    return sintable[sinpos_current];
}

void updateSin(uint8_t i){
    sinpos[index] = (sinpos_current+slopetable[slopepos_current])%256
	slopepos[i] = (slopepos_current+1)%256;
}

void scaleSin(uint8_t max){
	int i;
	for (i = ELEMCNT(sintable)-1; i>0; --i){
        sintable[i] = (sintable[i]*max)/SINMAX;
    }
}
