#include "busycircleInterface.h"

#define SINMAX 200

enum getSinStates_t{GETXSIN, GETYSIN, NOSINSTATE};

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
uint8_t index;

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
	static uint8_t state;
	int sinval;

	switch(state){
		case GETXSIN:
			slopepos_current = slopepos[index];
			sinval = sintable[sinpos_current = sinpos[index]];
			break;
		case GETYSIN:
			sinval = sintable[sinpos_current+64];
		default: break;
	}
	if (NOSINSTATE == ++state){
		state = 0;
	}

	return sinval;
}

void updateSin(speedTableElem_t *slopetable){
    sinpos[index] = (sinpos_current+slopetable[slopepos_current])%256;
	slopepos[index] = (slopepos_current+1)%256;
}

void scaleSin(uint8_t max){
	int i;
	for (i = ELEMCNT(sintable)-1; i>0; --i){
        sintable[i] = (sintable[i]*max)/SINMAX;
    }
}
