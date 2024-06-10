cc = gcc
flags = -Wall -pedantic -std=c99 -pthread
###___###
res 	: main alt prime	;
main 	: main.c stringW.h	; $(cc) $(flags) main.c -o main
alt 	: alt.c stringW.h	; $(cc) $(flags) alt.c -o alt
prime	: prime.c stringW.h	; $(cc) $(flags) -o prime prime.c -lm 
clean 	: 					; rm main alt prime
###___###
