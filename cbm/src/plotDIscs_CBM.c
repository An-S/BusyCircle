#include "busycircleInterface.h"

speedTableElem_t *slopetable;

void initDiscPlotter(size_t len, size_t seqlen, size_t max){
    slopetable = generateSpeedtable(len, seqlen, max);

    //scale sintable to appropriate radius
    scaleSin(88);
}
/*
int getCurrentSinpos(uint8_t i){
    return sinpos[i];
}

int getCurrentSlopepos(uint8_t i){
    return sinpos[i];
}
*/
void terminateDiscPlotter(void){
    if (slopetable) destroySpeedtable(slopetable);
}

/*
CBM_discRenderer(Renderer_t *renderer, Texture_t *texture, drawingObjTargetRect_t *renderRect){
    int x = (SCREEN_WIDTH/2)+sintable[sinpos[i]]-renderRect->w/2;
    int y = (SCREEN_HEIGHT/2)+sintable[sinpos[i]+64]-renderRect->h/2;
    getDrawingPosition(x,y,renderRect);

}*/

void plotDiscs(Resources_t *res, drawingObjTargetRect_t *renderRect){
    static uint8_t i, ix2;

    setSinOffsets(renderRect->x, renderRect->y);

	waitretrace();
	VIC.spr_hi_x = 0;
	VIC.bordercolor = 11;

    for (resetSinIndex(), ix2=0; getSinIndex()<DOTS; incSinIndex(),ix2+=2){
        //sinpos_current = getCurrentSinpos(i);
        //slopepos_current = getCurrentSlopepos(i);



        //sinx/=2;
        //siny/=2;

        //__AX__ = sinx; //(SCREEN_WIDTH/2)+sintable[sinpos[i]]-renderRect->w/2;
        __AX__ = getCurrentSinValue();

        asm("cpx #1");
        asm("ror %w", 0xd010);
        asm("ldx %v", ix2);
        asm("sta %w,x", 0xd000);
		++VIC.bordercolor;

			//__AX__ = siny;//(SCREEN_HEIGHT/2)+sintable[sinpos[i]+64]-renderRect->h/2;
        __AX__ = getCurrentSinValue();

        asm("ldx %v", ix2);
        asm("sta %w,x", 0xd001);
		++VIC.bordercolor;


        //updateSin(slopetable);
		//++VIC.bordercolor;

        //updateSlopepos();
		//incSinIndex();
        //sinpos[i] = (sinpos_current+slopetable[slopepos_current])%256;
        //slopepos[i] = (slopepos_current+1)%256;
//		VIC.spr_hi_x <<=1;
//
//        if ((sinx>>8) > 0) ++VIC.spr_hi_x;
        //SDL_RenderCopy(renderer, texture, 0, &renderRect);
    }
    VIC.bordercolor = 11;
}


