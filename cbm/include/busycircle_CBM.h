#ifndef BUSYCIRCLE_CBM_H_INCLUDED
#define BUSYCIRCLE_CBM_H_INCLUDED

    #include <carloslib.h>

    #define SCREEN_WIDTH (320+48)
    #define SCREEN_HEIGHT (300)

    typedef uint8_t drawingObjDim_t;

    typedef struct{
        int x,y;
        size_t w,h;
        //size_t dummy;
    }drawingObjTargetRect_t;

    typedef void Renderer_t(void);
    typedef void Texture_t(void);
	typedef void Target_t(void);

    int getVICSpriteRect(drawingObjTargetRect_t *rect);

#endif // BUSYCIRCLE_CBM_H_INCLUDED
