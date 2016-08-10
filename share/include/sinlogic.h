#ifndef SINLOGIC_H_INCLUDED
#define SINLOGIC_H_INCLUDED


void resetSinIndex(void);
uint8_t getSinIndex(void);
bool testSinIndexRange(uint8_t max);
void incSinIndex(void);
int getCurrentSinValue(void);
void updateSin(uint8_t i);
void scaleSin(uint8_t max);


#endif // SINLOGIC_H_INCLUDED
