#ifndef BUSYCIRCLE_H_INCLUDED
#define BUSYCIRCLE_H_INCLUDED

#define DOTS 8
#define DISTANCE 12
#define SLOPEDIST 4


typedef int speedTableElem_t;

speedTableElem_t *generateSpeedtable(size_t len, size_t seqlen, size_t max);
int destroySpeedtable(speedTableElem_t *speedTable);


void initResources(void);
void freeResources(void);

void setErrorAndExit(int exitcode);
int getError(void);

void initDiscPlotter(size_t len, size_t seqlen, size_t max);
void terminateDiscPlotter(void);

int mainProg(void);

int getDrawingObjectPosition(int x, int y, drawingObjDim_t w, drawingObjDim_t h, drawingObjTargetRect_t *);

#endif // BUSYCIRCLE_H_INCLUDED
