#include "sinlogic.h"

#ifdef CBM_TARGET

sinelem_t sintable[] = {
    #include "cbmsin.h"
};
#else
sinelem_t sintable[] = {
        #include "sintable.h"
};
#endif // CBM_TARGET

sinelem_t fastcall getSin(uint8_t /*pos*/){

    return
    asm("tax"),
    asm("lda %v,x", sintable),
    __AX__;
}

sinelem_t fastcall getCos(uint8_t /*pos*/){
    return
    asm("tax"),
    asm("lda %v+%b,x", sintable, ELEMCNT(sintable)/8),
    __AX__;
}

void scaleSin(int max){
	int i;
	for (i = 31/*ELEMCNT(sintable)-1*/; i>0; --i){
        sintable[i] = (sintable[i]*max)/SINMAX;
    }
}

