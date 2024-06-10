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
        else:
            a = random.random()
            if a >= 0.50:
                tests.append("! Save 1")
            else:
                pass
                tests.append("! Load 1")

    for word in in_arr:
        tests.append((" ".join(["-", str(word)])))
    tests.append("! Save 1")
    return tests

# main loop

start_size = input("how many iterations?\t")
str_length = 256
max_plank = 10000
in_arr = []

f = open('text.txt', "w")
test = generate_tests(start_size)
for i in test:
    f.write(i + '\n')
# f.write('p')
f.close()
