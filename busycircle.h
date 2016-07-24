#ifndef BUSYCIRCLE_H_INCLUDED
#define BUSYCIRCLE_H_INCLUDED

#include <stdheaders.h>

typedef int speedTableElem_t;

speedTableElem_t *generateSpeedtable(size_t len, size_t seqlen, size_t max);
int destroySpeedtable(speedTableElem_t *speedTable);

#endif // BUSYCIRCLE_H_INCLUDED
