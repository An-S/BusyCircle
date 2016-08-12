#ifndef SINLOGIC_H_INCLUDED
#define SINLOGIC_H_INCLUDED


void resetSinIndex(void);
uint8_t getSinIndex(void);
bool testSinIndexRange(uint8_t max);
void incSinIndex(void);
int getCurrentSinValue(void);
void updateSin(speedTableElem_t *slopetable);
void scaleSin(int max);
void setSinOffsets(int _xoffs, int _yoffs);

#endif // SINLOGIC_H_INCLUDED
