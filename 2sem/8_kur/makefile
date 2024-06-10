CC = gcc
LD = gcc
CCFLAGS = -Wall -pedantic  -std=c99
###____###
a.out: main.o list.o ; $(CC) $(CCFLAGS) -g main.o list.o
main.o: main.c list.h ; $(CC) $(CCFLAGS) -c -g main.c
list.o: list.c list.h ; $(CC) $(CCFLAGS) -c -g list.c
clean: ; rm *.o
###___###
