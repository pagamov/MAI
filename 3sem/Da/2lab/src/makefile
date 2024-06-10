CC = gcc
CCFLAGS = -Wall -pedantic -std=c99 -g
###____###
main		: code/main.o code/m.o code/delete.o code/insert.o code/clear.o code/saveload.o code/merge.o code/bTree.h ; $(CC) $(CCFLAGS) code/*.o -o main
m.o			: code/m.c code/bTree.h 		; $(CC) $(CCFLAGS) -c code/m.c 			; mv m.o src
delete.o	: code/delete.c code/bTree.h 	; $(CC) $(CCFLAGS) -c code/delete.c  	; mv delete.o src
insert.o	: code/insert.c code/bTree.h 	; $(CC) $(CCFLAGS) -c code/insert.c  	; mv insert.o src
clear.o 	: code/clear.c code/bTree.h		; $(CC) $(CCFLAGS) -c code/clear.c  	; mv clear.o src
main.o		: code/main.c code/bTree.h		; $(CC) $(CCFLAGS) -c code/main.c 		; mv main.o src
saveload.o	: code/saveload.c code/bTree.h	; $(CC) $(CCFLAGS) -c code/saveload.c 	; mv saveload.o src
merge.o		: code/merge.c code/bTree.h 	; $(CC) $(CCFLAGS) -c code/merge.c 		; mv merge.o src
clean		: ; rm code/*.o main
cleam		: ; rm code/*.o
gen 		: ; python generator.py
val 		: ; sudo /Applications/DrMemory-MacOS-2.2.1-alpha2/bin64/drmemory -- ./main
tar 		: ; mkdir solution ; cp code/*.h code/*.c code/makefile solution ; tar -cf solution.tar solution
tard		: ; rm -r solution solution.tar
valgrind 	: ; valgrind -s --leak-check=full ./main < text.txt > res.txt
callgrind 	: ; valgrind --tool=callgrind ./main < text.txt > res.txt
cache 		: ; kcachegrind
rec			: ; make clean; make; rm 1; valgrind -s --leak-check=full ./main < text.txt > res.txt
noneed		: ; rm 1 res.txt text.txt
test		: ; python tester.py
###___###
