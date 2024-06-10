CC = gcc
LD = gcc
CCFLAGS = -Wall -pedantic  -std=c99
###____###
a.out: main.o queue.o sort.o ; $(LD) -o a.out main.o queue.o sort.o
main.o: main.c queue.h sort.h ; $(CC) $(CCFLAGS) -c main.c
queue.o: queue.c queue.h ; $(CC) $(CCFLAGS) -c queue.c
sort.o: sort.c sort.h ; $(CC) $(CCFLAGS) -c sort.c
clean: ; rm *.o
###___###
