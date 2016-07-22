
#include <mclib.h>

MCLib_sintable_t * calcsin(size_t r){
    MCLib_sintable_t *sintab = MCLib_createSin(256, -r,r, 2);
    return sintab;
}

