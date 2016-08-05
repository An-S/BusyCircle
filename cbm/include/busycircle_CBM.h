#ifndef BUSYCIRCLE_CBM_H_INCLUDED
#define BUSYCIRCLE_CBM_H_INCLUDED

    typedef uint8_t drawingObjDim_t;

    typedef struct{
        int x,y;
        size_t w,h;
    }drawingObjTargetRect_t;

    typedef void Renderer_t(void);
	typedef void Target_t(void);
	
#endif // BUSYCIRCLE_CBM_H_INCLUDED
