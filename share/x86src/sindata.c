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

sinelem_t fastcall getSin(uint8_t pos){
    return sintable[pos];
}

sinelem_t fastcall getCos(uint8_t pos){
    return (sintable+ELEMCNT(sintable)/8)[pos];
}

void scaleSin(int max){
	int i;
	for (i = 31/*ELEMCNT(sintable)-1*/; i>0; --i){
        sintable[i] = (sintable[i]*max)/SINMAX;
    }
}

