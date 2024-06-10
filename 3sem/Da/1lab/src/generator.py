import random
import os, sys
import string
import subprocess
import time

def generate_tests(qty):
    max_plank = 65536
    tests = []
    for i in range(0, qty):
        key     = random.randrange(0, max_plank, 1)
        size    = random.randrange(10, str_length, 1)
        letters = string.ascii_lowercase
        val     = "".join(random.choice(letters) for _ in range(size))
        tests.append("\t".join([str(key), str(val)]))
    return tests

# main loop

range_ = input("How many loop?\t")
start_size = input("Start size?\t")
str_length = 2049

os.system("gcc -Wall -pedantic -std=c99 main.c -o prog")
os.system("gcc -Wall -pedantic -std=c99 main_2.c -o prog_2")
os.system("rm tests/res.txt; touch tests/res.txt")

while (range_ != 0):
    f = open('tests/text.txt', "w")
    test = generate_tests(start_size)
    for i in test:
        f.write(i + '\n')
    f.close()
    os.system("./prog < tests/text.txt >> tests/res.txt")
    os.system("./prog_2 < tests/text.txt >> tests/res.txt")
    start_size *= 2;
    range_ -= 1;

print("\nHere is result of sorting by main sort (left) and additional sort (right)")
os.system("rm prog prog_2; cat tests/res.txt")
