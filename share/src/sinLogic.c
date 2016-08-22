#include "busycircleInterface.h"



enum getSinStates_t{GETXSIN, GETYSIN, NOSINSTATE};

uint8_t sinpos[DOTS] =  	{
								0*DISTANCE,1*DISTANCE,2*DISTANCE,3*DISTANCE,
								4*DISTANCE,5*DISTANCE,6*DISTANCE,7*DISTANCE
							};

uint8_t slopepos[DOTS] = 	{
								0*SLOPEDIST, 1*SLOPEDIST, 2*SLOPEDIST, 3*SLOPEDIST,
								4*SLOPEDIST, 5*SLOPEDIST, 6*SLOPEDIST, 7*SLOPEDIST
							};

static uint8_t sinpos_current=0, slopepos_current=0;
static uint8_t sinindex=0, xoffs=0, yoffs=0;

void resetSinIndex(void){
	sinindex = 0;
}

uint8_t getSinIndex(void){
	return sinindex;
}

//bool testSinIndexRange(uint8_t max){
//	return index<max;
//}

void incSinIndex(void){
	++sinindex;
}

void setSinOffsets(int _xoffs, int _yoffs){
	xoffs = _xoffs;
	yoffs = _yoffs;
}

int getCurrentSinValue(void){
	static uint8_t state = GETXSIN;
	int sinval;

	switch(state){
		case GETXSIN:
			slopepos_current = slopepos[sinindex];
			sinval = (int)getSin(sinpos_current = sinpos[sinindex])+xoffs;
			break;
		case GETYSIN:
			sinval = (int)getCos(sinpos_current)+yoffs;
		default: break;
	}
	/*if (NOSINSTATE == ++state){
		state = GETXSIN;
	}*/
	//only two states. toggle them
	state ^= 1;

	return sinval;
}

void updateSin(speedTableElem_t *slopetable){
    sinpos[sinindex] = (sinpos_current+slopetable[slopepos_current]);
	slopepos[sinindex] = (slopepos_current+1);
}


