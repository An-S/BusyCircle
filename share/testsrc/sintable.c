#include <stdio.h>
#include <stdlib.h>
#include <MCLib.h>

MCLib_sintable_t *calcsin(size_t r);

int main(int argc, char *argv[])
{
    FILE *ofile;
    char *filename;// = "sintable.h";
    size_t r;
    MCLib_sintable_t *sin;

    if (3 != argc){
        printf("Usage: %s filename radius", argv[0]);
        exit(1);
    }
    filename = argv[1];
    ofile = fopen(filename, "wb");
    if (NULL == ofile) {
        perror("could not open file");
    }

    if ( 1!= sscanf(argv[2], "%u", &r){
        perror("bad radius");
        exit(2);
    }
    sin = calcsin(r);

    MCLib_fprintList(ofile, "%d", sin->sintable, MCLib_fprintIntElem, sin->size, 8);
    MCLib_fprintList(stdout, "%d", sin->sintable, MCLib_fprintIntElem, sin->len, 8);
    fclose(ofile);
    return 0;
}
