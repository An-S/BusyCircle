
#include "busycircleInterface.h"
//#include "Sprites/VIC2_Sprites.h"

extern VIC2SpriteBlock_t spriteDef;
extern VIC2SpritePointers_t spritePtr;

//hexdump -ve '"0x" /1 "%02x, "' ball.soj
uint8_t spriteSrcData[] = {
	0x01, 0xfc, 0x00, 0x07, 0xff, 0x00, 0x1f, 0xff, 0xc0, 0x3f, 0xff,
	0xe0, 0x3f, 0xff, 0xe0, 0x7f, 0xff, 0xf0, 0x7f, 0xff, 0xf0, 0xff,
	0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8,
	0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0x7f, 0xff,
	0xf0, 0x7f, 0xff, 0xf0, 0x3f, 0xff, 0xe0, 0x3f, 0xff, 0xe0, 0x1f,
	0xff, 0xc0, 0x07, 0xff, 0x00, 0x01, 0xfc, 0x00};

//uint8_t spriteDef[64];
//uint8_t spritePtr;

Renderer_t *getRenderer(void){
    return 0;//renderer;
}

Texture_t *getTexture(void){
    Texture_t *tex = malloc(sizeof(Texture_t));
    tex->sprDef = &spriteDef;
    tex->sprPtrs = &spritePtr;
    memcpy(spriteDef, spriteSrcData, SPR_BYTESIZE);

    return tex;//texture;
}

Resources_t *initResources(void){
    //asm("lda #>%w", spriteDef);
    //asm("")
    Resources_t *res = malloc(sizeof(Resources_t));
    res -> tex = getTexture();
    res -> rend = getRenderer();

    memset(spritePtr,
    (uint8_t)( (uintptr_t)spriteDef/SPR_BLOCKSIZE),
    sizeof(spritePtr));//__AX__;

	memset(&VIC.spr0_color, 1, 8);
    VIC.spr_ena = 0xff;
    initDiscPlotter(256, 16, 4);
    return res;
}

//frees the resources again
void freeResources(Resources_t *res){
    terminateDiscPlotter();
    free(res->tex);
    free(res->rend);
    free(res);
}


