cc = g++
flags = -Wall -pedantic -pthread -std=c++14 -g
###___###
res 	: main		;
main 	: main.cpp 	; $(cc) $(flags) main.cpp -o main
clean 	: 			; rm main
gen 	:			; python generator.py
###___###
