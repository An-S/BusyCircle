#include "busycircle.h"

speedTableElem_t *generateSpeedtable(size_t len, size_t seqlen, size_t max){
    size_t i;
    int *table = calloc(len,sizeof(int));
    for (i = 0; i < len; ++i){
        if (i >= 2*(max-1)*seqlen){
            table[len-i-1] = 2;
        }else{
            table[len-i-1] = max-abs(max/2-i/seqlen)+1;
        }
    }

    return table;
}

int destroySpeedtable(speedTableElem_t *speedTable){
    if (speedTable){
        free(speedTable);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
