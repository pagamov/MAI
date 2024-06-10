#include <stdio.h>
#include <stdlib.h>

#define input_1 u->name, &u->chipNum, u->chipType, &u->videoMemory, u->videoType
#define input_2 &u->vinNum, &u->vinMemory, &u->inContrl, &u->outContrl, u->osType

#include "genBase.h"

int size;
int response = 0;

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
	char (*osType)[SIZE], int osTypesize);

void usage()
{
	printf("Usage:\n");
	printf("ProgramName FileToCreate baseFile\n");
}

int readLog (struct updateLog *u)
{
	return (scanf("%s%d%s%d%s", input_1)
			+ scanf("%d%d%d%d%s", input_2) == 10);
}

int main(int argc, char* argv[])
{
	if (argc != 3) {
		usage();
		return 1;
	}
	srand(time(NULL));

	struct updateLog u;

	FILE * out = fopen(argv[1], "wb");
	if (!out) {
		perror("can't open");
		return 2;
	}
	FILE * base = fopen(argv[2], "r");
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

	printf("0. for hand enter\n");
	printf("1. for automatic generation\n");
	scanf("%d", &response);
	if (response == 0) {
		printf("убедитесь, что данные присутствуют\nв таблице рейтингов base.txt\n");
		while (readLog(&u)) {
			fwrite (&u, sizeof(struct updateLog), 1, out);
		}
	} else if (response == 1) {
		printf("сколько людей генерировать?	");
		scanf("%d", &response);
		for (int i = 0; i < response; i++) {
			randWriteLog(&u, i,
				name, (int)(sizeof(name)/sizeof(name[0])),
				chipNum, (int)(sizeof(chipNum)/sizeof(chipNum[0])),
				chipType, (int)(sizeof(chipType)/sizeof(chipType[0])),
				videoMemory, (int)(sizeof(videoMemory)/sizeof(videoMemory[0])),
				videoType, (int)(sizeof(videoType)/sizeof(videoType[0])),
				vinNum, (int)(sizeof(vinNum)/sizeof(vinNum[0])),
				vinMemory, (int)(sizeof(vinMemory)/sizeof(vinMemory[0])),
				inContrl, (int)(sizeof(inContrl)/sizeof(inContrl[0])),
				outContrl, (int)(sizeof(outContrl)/sizeof(outContrl[0])),
				osType, (int)(sizeof(osType)/sizeof(osType[0])));
			fwrite(&u, sizeof(struct updateLog), 1, out);
		}
	}
	fclose(out);
	return 0;
}
