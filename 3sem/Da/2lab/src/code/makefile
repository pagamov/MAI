CC = gcc
CCFLAGS = -Wall -pedantic -std=c99
###____###
solution	: main.o m.o delete.o insert.o clear.o saveload.o merge.o bTree.h ; $(CC) $(CCFLAGS) *.o -o solution
m.o			: m.c 		bTree.h ; $(CC) $(CCFLAGS) -c m.c
delete.o	: delete.c 	bTree.h ; $(CC) $(CCFLAGS) -c delete.c
insert.o	: insert.c 	bTree.h ; $(CC) $(CCFLAGS) -c insert.c
clear.o 	: clear.c 	bTree.h	; $(CC) $(CCFLAGS) -c clear.c
main.o		: main.c	bTree.h	; $(CC) $(CCFLAGS) -c main.c
saveload.o	: saveload.c bTree.h; $(CC) $(CCFLAGS) -c saveload.c
merge.o		: merge.c   bTree.h ; $(CC) $(CCFLAGS) -c merge.c
clean		: 					;
###___###
