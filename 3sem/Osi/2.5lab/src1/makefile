cc = gcc
flags = -Wall -pedantic -std=c99
###___###
res 	: main				; mv main ../
main 	: main.c stringW.h	; $(cc) $(flags) main.c -o main
alt 	: alt.c stringW.h	; $(cc) $(flags) alt.c -o alt
prime	: prime.c stringW.h	; $(cc) $(flags) prime.c -o prime
clean 	: 					;
###___###
