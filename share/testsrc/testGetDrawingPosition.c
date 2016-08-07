#include "busycircleInterface.h"

int main(void){
    size_t x=100, y=100, w=50, h=50;
    drawingObjTargetRect_t rect = {x,y,w,h};
    int retc;

    retc = getDrawingObjectPosition(x,y, &rect);

    printf("Original x:%d, y:%d, w:%d, h:%d\n"
            "Calculated x:%d, y:%d, w:%d, h:%d",
            x,y,w,h,
            rect.x, rect.y, rect.w, rect.h);
    printf("Return code:", retc);
    return 0;
}


