#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include "bmp.h"

typedef struct someArgs_t { // struct for thread_data[NTHREAD]
    int i, j, id;
	uint8_t data;
	BMPImage * image;
} someArgs_t;

#ifndef READIMAGE_OFF
void allocateArr(BMPImage * image) {
	image->pixels = malloc(image->norm_height * sizeof(Pixel *));
	memset(image->pixels,0,image->norm_height * sizeof(Pixel *));
	for(int i=0;i < image->norm_height;i++) {
		image->pixels[i] = malloc(image->header.width_px * sizeof(Pixel));
		memset(image->pixels[i],0,image->header.width_px * sizeof(Pixel));
	}
}
BMPImage * readImage(FILE * fp) {
	fseek(fp,0,SEEK_SET); //go to start of file
	//allocate structure and read header
	BMPImage * image = malloc(sizeof(BMPImage));
	fread(&(image->header),sizeof(image->header),1,fp);
	//make sure norm_height is always positive
	if (image->header.height_px < 1) {
		image->norm_height = image->header.height_px * -1;
	} else {
		image->norm_height = image->header.height_px;
	}
	//allocate 2d array of pixels
	allocateArr(image);
	//read pixels into array
    if (image->header.height_px < 1 ) { //if height is negative this means that the image is stored from bottom up
		fseek(fp,0,SEEK_END); //go to end
		for (int i = 0;i < image->norm_height;i++) {
			fseek(fp,image->header.width_px * -4,SEEK_CUR); //go to start of the row
			for(int j = 0; j <image->header.width_px;j++) {
				fread(&(image->pixels[i][j].blue),1,1,fp);
				fread(&(image->pixels[i][j].green),1,1,fp);
				fread(&(image->pixels[i][j].red),1,1,fp);
				fread(&(image->pixels[i][j].alpha),1,1,fp);
			}
			fseek(fp,image->header.width_px * -4,SEEK_CUR); //return to start of the row for next call back
		}
	} else {
		for (int i = 0;i < image->norm_height;i++) {
			for(int j = 0; j <image->header.width_px;j++) {
				fread(&(image->pixels[i][j].blue),1,1,fp);
				fread(&(image->pixels[i][j].green),1,1,fp);
				fread(&(image->pixels[i][j].red),1,1,fp);
				fread(&(image->pixels[i][j].alpha),1,1,fp);
			}
		}
	}
	return image;
}

void freeImage(BMPImage * image) {
	for (int i = 0;i < image->norm_height; i++) {
		free(image->pixels[i]);
	}
	free(image->pixels);
	free(image);
}
#endif

#ifndef WRITEIMAGE_OFF
void * thread_write(void * input) {
	someArgs_t * inp = (someArgs_t *)input;

	uint8_t mask[4] = {0xC0,0x30,0x0C,0x03};
	uint8_t clr = 0xC0 | 0x30 | 0x0C;

	uint8_t offset = 0x00; // can be from 0 to 3
	for (int i = inp->i; i < inp->image->norm_height; i++) {
		for (int j = inp->j; j < inp->image->header.width_px; j++) {
			if (offset < 0x04) {
				uint8_t d = inp->data;
				uint8_t w = inp->image->pixels[i][j].alpha & clr;
				d &= mask[offset];
				d = d >> (0x06 - 0x02 * offset);
				d &= mask[3];
				w = w | d;
				inp->image->pixels[i][j].alpha = w;
				offset++;
			} else {
				return 0;
			}
		}
	}
	return 0;
}

void writeImage(BMPImage * image, FILE * fp, char * data, char * nthread) {
	int NTHREAD = atoi(nthread);
	fprintf(stdout,"nthread: %d\n", NTHREAD);
	fseek(fp,0,SEEK_SET);
	int gh = 0; // from 0 to end of data
	int strend = strlen(data)+1;
	int curr = 0; // from 0 to 3
	int data_coll = 0; // from 0 to NTHREAD
	int status, status_addr;
	//write header
	fwrite(&(image->header),sizeof(image->header),1,fp);

	clock_t start = clock(), stop;

	pthread_t threads[NTHREAD];
	someArgs_t thread_data[NTHREAD];

	for (int i = 0; i < NTHREAD; i++) {
		thread_data[i].image = image;
	}

	for (int i = 0; i < image->norm_height; i++) {
		for (int j = 0; j < image->header.width_px; j++) {
			// parse data to arr
			if (curr == 0) {
				thread_data[data_coll].i = i;
				thread_data[data_coll].j = j;
				thread_data[data_coll].data = (uint8_t)data[gh];
				// thread_data[data_coll].curr = curr;
				data_coll++;
			}
			curr++;
			if (curr > 3) {
				curr = 0;
				gh++;
			}
			if (gh > strend) {
				data_coll = NTHREAD;
			}

			if (data_coll == NTHREAD) {
				// collected data start threads
				for (int n = 0; n < NTHREAD; n++) {
		            status = pthread_create(&threads[n], NULL, thread_write, (void*) &thread_data[n]);
		            if (status != 0) {
		                printf("main error: can't create thread, status = %d\n", status);
		                exit(-11);
		            }
		        }
		        for (int n = 0; n < NTHREAD; n++) {
		            status = pthread_join(threads[n], (void**) &status_addr);
		            if (status != 0) {
		                printf("main error: can't join thread, status = %d\n", status);
		                exit(-12);
		            }
		        }
				data_coll = 0;
			}
			if (gh > strend) {
				goto next;
			}
		}
	}
	next:
	stop = clock();
	fprintf(stdout,"done in : %f sec\n",((float)(stop - start)) / CLOCKS_PER_SEC);
	//write array into file
	for (int i = 0; i < image->norm_height; i++) {
		for (int j = 0; j < image->header.width_px; j++) {
			fwrite(&(image->pixels[i][j].blue),sizeof(uint8_t),1,fp);
			fwrite(&(image->pixels[i][j].green),sizeof(uint8_t),1,fp);
			fwrite(&(image->pixels[i][j].red),sizeof(uint8_t),1,fp);
			fwrite(&(image->pixels[i][j].alpha),sizeof(uint8_t),1,fp);
		}
	}
}
#endif

#ifndef DECODE
void * thread_decode(void * input) {
	someArgs_t * inp = (someArgs_t *)input;
	uint8_t mask[4] = {0xC0,0x30,0x0C,0x03};
	int done = 0;
	uint8_t charc = 0x00;
	for (int i = inp->i; i < inp->image->norm_height; i++) {
		for (int j = inp->j; j < inp->image->header.width_px; j++) {
			if (done < 4) {
				uint8_t w = inp->image->pixels[i][j].alpha;
				w = w & mask[3];
				w = w << (6 - 2*done);
				charc = charc | w;
				done++;
			} else {
				inp->data = charc;
				return 0;
			}
		}
	}
	return 0;
}

void decode(BMPImage * image, char * nthread) {
	int NTHREAD = atoi(nthread);
	fprintf(stdout,"nthread: %d\n", NTHREAD);
	int curr = 0; // from 0 to 3

	clock_t start = clock(), stop;

	char textbuf[4096];
	int tb_idx = 0;
	int data_coll = 0;
	int EXIT_FLAG = 0;
	int status, status_addr;

	pthread_t threads[NTHREAD];
	someArgs_t thread_data[NTHREAD];

	for (int i = 0; i < NTHREAD; i++) {
		thread_data[i].image = image;
		thread_data[i].id = i;
	}

	for (int i = 0; i < image->norm_height;i++) {
		for (int j = 0; j < image->header.width_px;j++) {
			if (curr == 0) {
				thread_data[data_coll].i = i;
				thread_data[data_coll].j = j;
				data_coll++;
			}
			curr++;
			if (curr > 3) {
				curr = 0;
			}
			if (data_coll == NTHREAD) {
				// collected data start threads
				for (int n = 0; n < NTHREAD; n++) {
		            status = pthread_create(&threads[n], NULL, thread_decode, (void*) &thread_data[n]);
		            if (status != 0) {
		                printf("main error: can't create thread, status = %d\n", status);
		                exit(-11);
		            }
		        }

		        for (int n = 0; n < NTHREAD; n++) {
		            status = pthread_join(threads[n], (void**) &status_addr);
		            if (status != 0) {
		                printf("main error: can't join thread, status = %d\n", status);
		                exit(-12);
		            }
		        }

				for (int n = 0; n < NTHREAD; n++) {
					textbuf[tb_idx+thread_data[n].id] = (char)thread_data[n].data;
					if ((char)thread_data[n].data == '\0') {
						EXIT_FLAG = 1;
					}
			   	}
				tb_idx += NTHREAD;
				// collect data from threads to text buffer
				data_coll = 0;
			}
			if (EXIT_FLAG) {
				goto nxt;
			}
		}
	}

	nxt:
	stop = clock();
	fprintf(stdout,"\n%s\n",textbuf);
	fprintf(stdout,"done in : %f sec\n",((float)(stop - start)) / CLOCKS_PER_SEC);
}
#endif
