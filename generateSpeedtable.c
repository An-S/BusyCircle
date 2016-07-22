
generateSpeedtable(size_t len, size_t seqlen, size_t max){
    size_t i;
    int *table = calloc(len,sizeof(int));
    for (i = 0; i < len; ++i){
        table[i] = 1;
    }

    return table;
}
