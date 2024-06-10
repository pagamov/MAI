#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "updateLog.h"
#include "baseWithRating.h"

#define SIZE 10

struct updateLogSr {
	int chipNum;
	int chipType;
	int videoMemory;
	int vinNum;
	int vinMemory;
	int inContrl;
	int outContrl;
	int osType;
};

void makeSr(struct updateLog *res, struct updateLogSr *sr,
		int * chipNum, int chipNumsize, int * chipNumR,
		char (*chipType)[SIZE], int chipTypesize, int * chipTypeR,
		int * videoMemory, int videoMemorysize, int * videoMemoryR,
		int * vinNum, int vinNumsize, int * vinNumR,
		int * vinMemory, int vinMemorysize, int * vinMemoryR,
		int * inContrl, int inContrlsize, int * inContrlR,
		int * outContrl, int outContrlsize, int * outContrlR,
		char (*osType)[SIZE], int osTypesize, int * osTypeR
)
{
	for (int i = 0; i < chipNumsize; i++) {
		if (chipNum[i] == res->chipNum) {
			sr->chipNum += chipNumR[i];
		}
	}
	for (int i = 0; i < chipTypesize; i++) {
		if (strcmp(chipType[i], res->chipType) == 0) {
			sr->chipType += chipTypeR[i];
		}
	}
	for (int i = 0; i < videoMemorysize; i++) {
		if (videoMemory[i] == res->videoMemory) {
			sr->videoMemory += videoMemoryR[i];
		}
	}
	for (int i = 0; i < vinNumsize; i++) {
		if (vinNum[i] == res->vinNum) {
			sr->vinNum += vinNumR[i];
		}
	}
	for (int i = 0; i < vinMemorysize; i++) {
		if (vinMemory[i] == res->vinMemory) {
			sr->vinMemory += vinMemoryR[i];
		}
	}
	for (int i = 0; i < inContrlsize; i++) {
		if (inContrl[i] == res->inContrl) {
			sr->inContrl += inContrlR[i];
		}
	}
	for (int i = 0; i < outContrlsize; i++) {
		if (outContrl[i] == res->outContrl) {
			sr->outContrl += outContrlR[i];
		}
	}
	for (int i = 0; i < osTypesize; i++) {
		if (strcmp(osType[i], res->osType) == 0){

			sr->osType += osTypeR[i];
		}
	}
}

void finalSr(struct updateLogSr *sr, int number)
{
	sr->chipNum /= number;
	sr->chipType /= number;
	sr->videoMemory /= number;
	sr->vinNum /= number;
	sr->vinMemory /= number;
	sr->inContrl /= number;
	sr->outContrl /= number;
	sr->osType /= number;
}

void postInfoHeaders(FILE *out, int iteration) {
	switch (iteration) {
		case 0:
		fprintf(out, "----------- ");
		fprintf(out, "chipNum Update\n");
		break;
		case 1:
		fprintf(out, "\n----------- ");
		fprintf(out, "chipType Update\n");
		break;
		case 2:
		fprintf(out, "\n----------- ");
		fprintf(out, "videoMemory Update\n");
		break;
		case 3:
		fprintf(out, "\n----------- ");
		fprintf(out, "vinNum Update\n");
		break;
		case 4:
		fprintf(out, "\n----------- ");
		fprintf(out, "vinMemory Update\n");
		break;
		case 5:
		fprintf(out, "\n----------- ");
		fprintf(out, "inContrl Update\n");
		break;
		case 6:
		fprintf(out, "\n----------- ");
		fprintf(out, "outContrl Update\n");
		break;
		case 7:
		fprintf(out, "\n----------- ");
		fprintf(out, "osType Update\n");
		break;
	}
}

void postInfo(struct updateLog *res, struct updateLogSr *sr, FILE *out, int iteration,
	int * chipNum, int chipNumsize, int * chipNumR,
	char (*chipType)[SIZE], int chipTypesize, int * chipTypeR,
	int * videoMemory, int videoMemorysize, int * videoMemoryR,
	int * vinNum, int vinNumsize, int * vinNumR,
	int * vinMemory, int vinMemorysize, int * vinMemoryR,
	int * inContrl, int inContrlsize, int * inContrlR,
	int * outContrl, int outContrlsize, int * outContrlR,
	char (*osType)[SIZE], int osTypesize, int * osTypeR
)
{
	switch (iteration) {
		case 0:
		for (int i = 0; i < chipNumsize; i++) {
			if (chipNum[i] == res->chipNum) {
				if (chipNumR[i] < sr->chipNum) {
					fprintf(out, "%s\t", res->name);
				}
			}
		}
		break;
		case 1:
		for (int i = 0; i < chipTypesize; i++) {
			if (strcmp(chipType[i], res->chipType) == 0) {
				if (chipTypeR[i] < sr->chipType) {
					fprintf(out, "%s\t", res->name);
				}
			}
		}
		break;
		case 2:
		for (int i = 0; i < videoMemorysize; i++) {
			if (videoMemory[i] == res->videoMemory) {
				if (videoMemoryR[i] < sr->videoMemory) {
					fprintf(out, "%s\t", res->name);
				}
			}
		}
		break;
		case 3:
		for (int i = 0; i < vinNumsize; i++) {
			if (vinNum[i] == res->vinNum) {
				if (vinNumR[i] < sr->vinNum) {
					fprintf(out, "%s\t", res->name);
				}
			}
		}
		break;
		case 4:
		for (int i = 0; i < vinMemorysize; i++) {
			if (vinMemory[i] == res->vinMemory) {
				if (vinMemoryR[i] < sr->vinMemory) {
					fprintf(out, "%s\t", res->name);
				}
			}
		}
		break;
		case 5:
		for (int i = 0; i < inContrlsize; i++) {
			if (inContrl[i] == res->inContrl) {
				if (inContrlR[i] < sr->inContrl) {
					fprintf(out, "%s\t", res->name);
				}
			}
		}
		break;
		case 6:
		for (int i = 0; i < outContrlsize; i++) {
			if (outContrl[i] == res->outContrl) {
				if (outContrlR[i] < sr->outContrl) {
					fprintf(out, "%s\t", res->name);
				}
			}
		}
		break;
		case 7:
		for (int i = 0; i < osTypesize; i++) {
			if (strcmp(osType[i], res->osType) == 0) {
				if (osTypeR[i] < sr->osType) {
					fprintf(out, "%s\t", res->name);
				}
			}
		}
		break;
	}
}
