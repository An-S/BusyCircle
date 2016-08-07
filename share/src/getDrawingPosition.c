
#include "busycircleInterface.h"

int getDrawingObjectPosition(int x, int y, drawingObjTargetRect_t *dt){
 //   drawingObjTargetRect_t dt;
    dt->x = x-dt->w/2;
    dt->y = y-dt->w/2;
    //dt->w = w;
    //dt->h = h;
    return 0;
}
