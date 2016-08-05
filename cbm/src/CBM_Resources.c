
#include "busycircleInterface.h"
//#include "Sprites/VIC2_Sprites.h"

/*extern uint8_t spriteDef[];
extern uint8_t spritePtr;
*/
uint8_t spriteDef[64];
uint8_t spritePtr;

void initResources(void){
    memset(spriteDef,0xff, SPR_BYTESIZE);
    //asm("lda #>%w", spriteDef);
    //asm("")
    spritePtr = ( (uint8_t)spriteDef/SPR_BLOCKSIZE )&255;//__AX__;
    atexit(freeResources);

    initDiscPlotter(256, 16, 4);

}

//frees the resources again
void freeResources(void){
    terminateDiscPlotter();
}


