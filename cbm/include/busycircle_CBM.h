#ifndef BUSYCIRCLE_CBM_H_INCLUDED
#define BUSYCIRCLE_CBM_H_INCLUDED

    #include <carloslib.h>

    #define SCREEN_WIDTH (320+48)
    #define SCREEN_HEIGHT (300)

    typedef uint8_t drawingObjDim_t;

    //define structure for size and position of sprite resembling
    //SDL_Rect
    typedef struct{
        int x,y;
        size_t w,h;
        //size_t dummy;
    }drawingObjTargetRect_t;

    typedef void Renderer_t(void);

    //define texture struct which holds sprite definition similar to
    //SDL_Texture which holds the shape definition of the discs to be drawn
    typedef struct{
        VIC2SpriteBlock_t *sprDef;
        VIC2SpritePointers_t *sprPtrs;
    } Texture_t;

   	int getVICSpriteRect(drawingObjTargetRect_t *rect);

#endif // BUSYCIRCLE_CBM_H_INCLUDED
