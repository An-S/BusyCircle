#include "busycircleInterface.h"

#define X 100
#define Y 100
#define W 50
#define H 50

int main(void){
    size_t x=X, y=Y, w=W, h=H;
    drawingObjTargetRect_t rect = {X,Y,W,H};
    int retc;

    retc = getDrawingObjectPosition(x,y, &rect);

    printf("Original x:%d, y:%d, w:%d, h:%d\n"
            "Calculated x:%d, y:%d, w:%d, h:%d",
            x,y,w,h,
            rect.x, rect.y, rect.w, rect.h);
    printf("Return code:", retc);
    return 0;
}


