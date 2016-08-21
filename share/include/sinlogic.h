#ifndef SINLOGIC_H_INCLUDED
#define SINLOGIC_H_INCLUDED

#include <busycircleInterface.h>

#ifdef CBM_TARGET
    #define SINMAX 127
    typedef int8_t sinelem_t;
#else
    #define SINMAX 200
    typedef int sinelem_t;
#endif

void resetSinIndex(void);
uint8_t getSinIndex(void);
bool testSinIndexRange(uint8_t max);
void incSinIndex(void);
int getCurrentSinValue(void);
void updateSin(speedTableElem_t *slopetable);
void scaleSin(int max);
void setSinOffsets(int _xoffs, int _yoffs);
sinelem_t getSin(uint8_t pos);
sinelem_t getCos(uint8_t pos);

#endif // SINLOGIC_H_INCLUDED
