CC = gcc
CC_FLAGS = -Wall -pedantic  -std=c99
VAL_FLAGS = --leak-check=full --show-leak-kinds=all -v
###____###
program: main.o table.o ; $(CC) $(CC_FLAGS) -g main.o table.o -o program
main.o: main.c table.h ; $(CC) $(CC_FLAGS) -c -g main.c
table.o: table.c table.h ; $(CC) $(CC_FLAGS) -c -g table.c
val: ; valgrind  $(VAL_FLAGS) ./program
clean: ; rm *.o
###___###
