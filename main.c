#include <stdio.h>
#include <stdlib.h>
#include <MCLib.h>

MCLib_sintable_t *calcsin(size_t r);

int main()
{
    FILE *ofile;
    char *filename = "sintable.h";
    MCLib_sintable_t *sin = calcsin(200);

    ofile = fopen(filename, "wb");
    if (NULL == ofile) {
        perror("could not open file");
    }
    MCLib_fprintList(ofile, "%d", sin->sintable, MCLib_fprintIntElem, sin->size, 8);
    //MCLib_fprintList(stdout, "%d", sin->sintable, MCLib_fprintIntElem, sin->len, 8);
    fclose(ofile);
    return 0;
}
