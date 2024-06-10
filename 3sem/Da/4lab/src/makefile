CC = g++
CCFLAGS = -std=c++11 -Wall -pedantic
###____###
main 	: code/main.cpp code/*.hpp ; $(CC) $(CCFLAGS) -o main code/main.cpp
clean		: ; rm main
tar 	: ; mkdir solution ; cp code/*.hpp code/*.cpp code/makefile solution ; tar -cf solution.tar solution
tard	: solution/ solution.tar ; rm -r solution solution.tar
test		: ; python Tester.py
cleant		: ; rm *.txt
check		: ; python Checker.py
valgrind 	: ; valgrind -s --leak-check=full --track-origins=yes ./main < test.txt > res.txt
callgrind 	: ; valgrind --tool=callgrind ./main < test.txt > res.txt
cache 		: ; kcachegrind
###___###
