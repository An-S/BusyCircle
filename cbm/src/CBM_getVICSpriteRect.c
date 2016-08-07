#include "busycircleInterface.h"

int getVICSpriteRect(drawingObjTargetRect_t *rect){
    rect->w = SPR_XSIZE_NEXP;
    rect->h = SPR_YSIZE_NEXP;
    rect->x = 172; //24+320/2-24/2
    rect->y = 162; //50+200/2-21/2

    return 0;
}
