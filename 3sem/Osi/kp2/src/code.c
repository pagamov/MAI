#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

int main(int argc, char ** argv) {
	if (argc != 5) {
		fprintf(stderr,"not enought parametrs\n");
		return EXIT_FAILURE;
	}
	fprintf(stdout,"size of: %lu, %lu\n", sizeof(uint8_t), sizeof(char));
	int size_biff = 16000;
	char textbuf[size_biff]; // memset buffer for text
	FILE * fp;
	fp = fopen(argv[3],"r");
	memset(textbuf, 0, size_biff);
	fread(textbuf, 1, size_biff, fp);
	fclose(fp);
	fprintf(stdout,"size: %lu\n", strlen(textbuf));
	FILE * inputp = fopen(argv[1],"rb"); // open read file in binary
	if (inputp == NULL) return EXIT_FAILURE;
	BMPImage * image = readImage(inputp);
	FILE * outputp = fopen(argv[2],"wb"); // open write file in binary
	if (outputp == NULL) return EXIT_FAILURE;
	writeImage(image,outputp,textbuf,argv[4]);
	freeImage(image);
	fclose(inputp);
	fclose(outputp);
	return EXIT_SUCCESS;
}
