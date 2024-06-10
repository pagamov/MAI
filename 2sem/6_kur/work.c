#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getBase.h"

void usage()
{
	printf("Usage:\n");
	printf("ProgramName FileToWorkWith FileToCreate base.txt\n");
}

int keyCheck(char *string1, char *string2)
{
	if (strncmp(string1, string2, 2) != 0) {
		return 0;
	} else {
		return 1;
	}
}

int main (int argc, char* argv[])
{

	if (argc != 4) {
		usage();
		return 1;
	}

	FILE * in = fopen(argv[1], "rb");
	if (!in) {
		perror("can't open");
		return 2;
	}

	FILE * out = fopen(argv[2], "w");
	if (!out) {
		perror("can't open");
		return 2;
	}

	FILE * base = fopen(argv[3], "r");
	if (!out) {
		perror("can't open");
		return 2;
	}

	requestS(base, &size);
  char name[size][SIZE];
  requesttaC(base, name, size);

  requestS(base, &size);
  int chipNum[size];
  int chipNumR[size];
  requesttaIR(base, chipNum, chipNumR, size);

  requestS(base, &size);
  char chipType[size][SIZE];
  int chipTypeR[size];
  requesttaCR(base, chipType, chipTypeR, size);

  requestS(base, &size);
  int videoMemory[size];
  int videoMemoryR[size];
  requesttaIR(base, videoMemory, videoMemoryR, size);

  requestS(base, &size);
  char videoType[size][SIZE];
  requesttaC(base, videoType, size);

  requestS(base, &size);
  int vinNum[size];
  int vinNumR[size];
  requesttaIR(base, vinNum, vinNumR, size);

  requestS(base, &size);
  int vinMemory[size];
  int vinMemoryR[size];
  requesttaIR(base, vinMemory, vinMemoryR, size);

  requestS(base, &size);
  int inContrl[size];
  int inContrlR[size];
  requesttaIR(base, inContrl, inContrlR, size);

  requestS(base, &size);
  int outContrl[size];
  int outContrlR[size];
  requesttaIR(base, outContrl, outContrlR, size);

  requestS(base, &size);
  char osType[size][SIZE];
  int osTypeR[size];
  requesttaCR(base, osType, osTypeR, size);

	fclose(base);
	//сколько студентов всего
	int number = 0;
	struct updateLog res;
	struct updateLogSr sr = {0, 0, 0, 0, 0, 0, 0, 0};

	while(fread(&res, sizeof(struct updateLog), 1, in) == 1) {
			makeSr(&res, &sr,
				chipNum, (int)(sizeof(chipNum)/sizeof(chipNum[0])), chipNumR,
				chipType, (int)(sizeof(chipType)/sizeof(chipType[0])), chipTypeR,
				videoMemory, (int)(sizeof(videoMemory)/sizeof(videoMemory[0])), videoMemoryR,
				vinNum, (int)(sizeof(vinNum)/sizeof(vinNum[0])), vinNumR,
				vinMemory, (int)(sizeof(vinMemory)/sizeof(vinMemory[0])), vinMemoryR,
				inContrl, (int)(sizeof(inContrl)/sizeof(inContrl[0])), inContrlR,
				outContrl, (int)(sizeof(outContrl)/sizeof(outContrl[0])), outContrlR,
				osType, (int)(sizeof(osType)/sizeof(osType[0])), osTypeR
			);
			++number;
	}
	finalSr(&sr, number);

	for (int i = 0; i < 8; i++) {
		fseek(in, 0, SEEK_SET);
		postInfoHeaders(out, i);
		while(fread(&res, sizeof(struct updateLog), 1, in) == 1) {
			postInfo(&res, &sr, out, i,
				chipNum, (int)(sizeof(chipNum)/sizeof(chipNum[0])), chipNumR,
				chipType, (int)(sizeof(chipType)/sizeof(chipType[0])), chipTypeR,
				videoMemory, (int)(sizeof(videoMemory)/sizeof(videoMemory[0])), videoMemoryR,
				vinNum, (int)(sizeof(vinNum)/sizeof(vinNum[0])), vinNumR,
				vinMemory, (int)(sizeof(vinMemory)/sizeof(vinMemory[0])), vinMemoryR,
				inContrl, (int)(sizeof(inContrl)/sizeof(inContrl[0])), inContrlR,
				outContrl, (int)(sizeof(outContrl)/sizeof(outContrl[0])), outContrlR,
				osType, (int)(sizeof(osType)/sizeof(osType[0])), osTypeR);
		}

	}
	fclose(in);
	fclose(out);
	return 0;
}
