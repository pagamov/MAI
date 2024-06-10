cc = gcc
flags = -Wall -pedantic -std=c99
###___###
res 	: main server									   ;
main 	: src1/main.c src1/stringW.h					   ; $(cc) $(flags) src1/main.c -o main
alt 	: src1/alt.c src1/stringW.h						   ; $(cc) $(flags) src1/alt.c -o alt
prime	: src1/prime.c src1/stringW.h					   ; $(cc) $(flags) src1/prime.c -o prime
clean 	: src2/*.o main server							   ; rm src2/*.o main server
server	: src2/main.o src2/list.o src2/tree.o src2/array.o ; $(cc) $(flags) -g src2/main.o src2/list.o src2/tree.o src2/array.o -o server
main.o	: src2/main.c src2/list.h src2/tree.h src2/array.h ; $(cc) $(flags) -c -g src2/main.c 	; mv main.o src2/
list.o	: src2/list.c src2/list.h src2/tree.h src2/array.h ; $(cc) $(flags) -c -g src2/list.c 	; mv list.o src2/
array.o	: src2/array.c src2/array.h						   ; $(cc) $(flags) -c -g src2/array.c	; mv list.o src2/
tree.o	: src2/tree.c src2/tree.h src2/array.h src2/list.h ; $(cc) $(flags) -c -g src2/tree.c 	; mv tree.o src2/
###___###
