import random
import os, sys
import string
import subprocess
import time

def generate_tests(qty):
    numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f']
    max_plank = 9
    tests = []
    for i in range(0, qty):
        size = random.randrange(1, str_length, 1)

        number = ""
        for value in range(size):
            number = "".join([number, random.choice(numbers)])
        tests.append(number)
    return tests

# main loop

range_ = input("How many numbers?\t")
str_length = 128

f = open('text.txt', "w")
test = generate_tests(range_)
for i in test:
    f.write(i + '\n')
f.close()
