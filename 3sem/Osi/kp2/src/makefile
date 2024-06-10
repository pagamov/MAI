# numbers of threads
NTHREAD = 4
flag = -std=c99 -Wall -pedantic -lpthread

# pic.bmp to code from
pic1 = leo.bmp
# pic.bmo to code in to
pic2 = res.bmp

# run make r1 to code in to file
r1 : ; ./code.out $(pic1) $(pic2) data.txt $(NTHREAD)
# run make r2 to decode from file
r2 : ; ./decode.out $(pic2) $(NTHREAD)

# run make code to compile code.out
code : code.c $(pic1) ; gcc $(flag) code.c bmp.c -o code.out
# run make decode to compile decode.out
decode : decode.c pic.bmp ; gcc $(flag) decode.c bmp.c -o decode.out

# run make clean to clean dir from trash files
clean : res.bmp ; rm res.bmp code.out decode.out

tar : ; mkdir solution ; cp *.h *.c makefile *.bmp *.txt solution ; tar -cf solution.tar solution
