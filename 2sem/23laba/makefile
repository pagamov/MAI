CC = gcc
LD = gcc
CCFLAGS = -Wall -pedantic  -std=c99
###____###
program: main.o tree.o ; $(CC) $(CCFLAGS) -g main.o tree.o -o program
main.o: main.c tree.h ; $(CC) $(CCFLAGS) -c -g main.c
tree.o: tree.c tree.h ; $(CC) $(CCFLAGS) -c -g tree.c
clean: ; rm *.o
###___###
