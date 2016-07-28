
#include "busycircle.h"
#include "sprites/VIC2_Sprites.h"

extern uint8_t spriteDef[];
extern uint8_t spritePtr;

void initResources(void){
    memset(spriteDef,0xff, SPR_BYTESIZE);
    //asm("lda #>%w", spriteDef);
    //asm("")
    spritePtr = (spriteDef/SPR_BLOCKSIZE)&255;//__AX__;
}

