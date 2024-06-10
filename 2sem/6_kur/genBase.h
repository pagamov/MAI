#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "updateLog.h"
#include "baseWithRating.h"

#define SIZE 10

int ran(int start, int max) {
	return start + rand() % max;
}

void randWriteLog (struct updateLog * u, int number,
	char (*name)[SIZE], int namesize,
	int * chipNum, int chipNumsize,
	char (*chipType)[SIZE], int chipTypesize,
	int * videoMemory, int videoMemorysize,
	char (*videoType)[SIZE], int videoTypesize,
	int * vinNum, int vinNumsize,
	int * vinMemory, int vinMemorysize,
	int * inContrl, int inContrlsize,
	int * outContrl, int outContrlsize,
	char (*osType)[SIZE], int osTypesize)
{
	int i;
	namesize++;
	i = number;
	for (int j = 0; j < SIZE; j++)
		u->name[j] = name[i][j];

	i = ran(0, chipNumsize);
		u->chipNum = chipNum[i];

	i = ran(0, chipTypesize);
	for (int j = 0; j < SIZE; j++)
		u->chipType[j] = chipType[i][j];

	i = ran(0, videoMemorysize);
		u->videoMemory = videoMemory[i];

	i = ran(0, videoTypesize);
		for (int j = 0; j < SIZE; j++)
			u->videoType[j] = videoType[i][j];

	i = ran(0, vinNumsize);
		u->vinNum = vinNum[i];

	i = ran(0, vinMemorysize);
		u->vinMemory = vinMemory[i];

	i = ran(0, inContrlsize);
		u->inContrl = inContrl[i];

	i = ran(0, outContrlsize);
		u->outContrl = outContrl[i];

	i = ran(0, osTypesize);
		for (int j = 0; j < SIZE; j++)
			u->osType[j] = osType[i][j];
}
