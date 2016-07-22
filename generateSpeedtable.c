#include "busycircle.h"

int *generateSpeedtable(size_t len, size_t seqlen, size_t max){
    size_t i;
    int *table = calloc(len,sizeof(int));
    for (i = 0; i < len; ++i){
        if (i > 2*(max-1)*seqlen){
            table[i] = 1;
        }else{
            table[i] = i/seqlen+2;
        }
    }

    return table;
}
