#include <stdio.h>
#include <stdlib.h>
#include <MCLib.h>

MCLib_sintable_t *calcsin(size_t r);

int main(int argc, char *argv[])
{
    FILE *ofile;
    char *filename = "sintable.h";
    MCLib_sintable_t *sin;
	size_t radius;

	if (argc != 5){
		printf("Usage: %s outfile max min length", argv[0]);
	}

    ofile = fopen(argv[1], "wb");
    if (NULL == ofile) {
        perror("could not open file");
        return 1;
    }

    if ((1 != sscanf(argv[1], "%d", &radius)) ){
		perror("scan error");
		return 2;
    }

    sin = calcsin(atoi(argv[2]));
    MCLib_fprintList(ofile, "%d", sin->sintable, MCLib_fprintIntElem, sin->size, 8);
    MCLib_fprintList(stdout, "%d", sin->sintable, MCLib_fprintIntElem, sin->len, 8);
    fclose(ofile);
    return 0;
}
