
#include "busycircle.h"
#include <MCLib.h>

int main(void){
    int *table = generateSpeedtable(256, 8, 4);
    MCLib_fprintList(stdout, "%d", table, MCLib_fprintIntElem, 256, 8);

    return 0;
}
