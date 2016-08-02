
#include "busycircleInterface.h"

drawingObjTargetRect_t getDrawingObjectPosition(int x, int y, drawingObjDim_t w, drawingObjDim_t h){
    drawingObjTargetRect_t dt;
    dt.x = x-w/2;
    dt.y = y-w/2;
    return dt;
}
