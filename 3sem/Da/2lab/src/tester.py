import random
import os, sys
import string
import subprocess
import time

def generate_tests(qty):
    tests = []
    tests.append(str(start_size))
    for i in range(0, qty):
        a = random.random()
        size    = random.randrange(1, str_length, 1)
        letters = string.ascii_lowercase
        if a >= 0.7:
            val     = "".join(random.choice(letters) for _ in range(size))
            key     = random.randrange(0, max_plank, 1)
            tests.append((" ".join(["+", str(val)])) + " " + str(key))
            in_arr.append(val)
        elif a < 0.7 and a >= 0.30:
            if len(in_arr) == 0:
                val     = "".join(random.choice(letters) for _ in range(size))
                key     = random.randrange(0, max_plank, 1)
                tests.append((" ".join(["+", str(val)])) + " " + str(key))
                in_arr.append(val)
            else:
                a = random.randint(0, len(in_arr) - 1);
                tests.append((" ".join(["-", str(in_arr[a])])))
                in_arr.remove(in_arr[a])
        elif a < 0.3 and a >= 0.1:
            val     = "".join(random.choice(letters) for _ in range(size))
            tests.append(str(val))
        # else:
        #     a = random.random()
        #     if a >= 0.50:
        #         tests.append("! Save 1")
        #     else:
        #         pass
        #         tests.append("! Load 1")
    return tests

def makeFile(size, file):
    f = open(file, "w")
    test = generate_tests(size)
    for i in test:
        f.write(i + '\n')
    f.close()

# main loop

str_length = 256
max_plank = 10000
in_arr = []

range_ = input("How many loop?\t")
start_size = input("Start size?\t")

os.system("make clean")
os.system("make")
os.system("g++ main.cpp")
os.system("rm text.txt res.txt res2.txt 1")

while (range_ != 0):
    makeFile(start_size, "text.txt")
    os.system("./main < text.txt >> res.txt")
    os.system("./a.out < text.txt >> res2.txt")
    start_size *= 2;
    range_ -= 1;

os.system("make clean")
os.system("rm text.txt 1")
