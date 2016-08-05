
#include "busycircleInterface.h"

int getDrawingObjectPosition(int x, int y, drawingObjDim_t w, drawingObjDim_t h, drawingObjTargetRect_t *dt){
 //   drawingObjTargetRect_t dt;
    dt->x = x-w/2;
    dt->y = y-w/2;
    return 0;
}
