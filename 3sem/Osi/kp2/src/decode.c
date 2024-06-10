#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

int main(int argc, char ** argv) {
	if (argc != 3) return EXIT_FAILURE;
	fprintf(stdout,"decoding from: %s\n\n",argv[1]);
	FILE * inputp = fopen(argv[1],"rb"); // open file in binary
	if (inputp == NULL) return EXIT_FAILURE;
	BMPImage * image = readImage(inputp);
    decode(image, argv[2]);
	freeImage(image);
	fclose(inputp);
	return EXIT_SUCCESS;
}
