CC = gcc
CCFLAGS = -Wall -pedantic  -std=c99
###____###
server: main.o list.o tree.o array.o ; $(CC) $(CCFLAGS) -g main.o list.o tree.o array.o -o server ; mv server ../
main.o: main.c list.h tree.h array.h ; $(CC) $(CCFLAGS) -c -g main.c
list.o: list.c list.h tree.h array.h ; $(CC) $(CCFLAGS) -c -g list.c
array.o: array.c array.h ; $(CC) $(CCFLAGS) -c -g array.c
tree.o: tree.c tree.h array.h list.h ; $(CC) $(CCFLAGS) -c -g tree.c
clean: ; rm *.o
###___###
