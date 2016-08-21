#include "sinlogic.h"

int sintable[] = {
    #ifdef CBM_TARGET
        #include "cbmsin.h"
    #else
        #include "sintable.h"
    #endif
    /*,
    #include "sintable.h"*/
};

