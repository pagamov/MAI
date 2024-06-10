import random
import os, sys
import string
import subprocess
import time

size_word = 2

def make_pattern(size_pattern, file1, arg1, file2, arg2):
    pattern = []
    max_size_pattern = size_word

    file_1 = open(file1, arg1)
    file_2 = open(file2, arg2)

    file_1.write(str(size_pattern) + "\n")

    for iter in range(size_pattern):
        letters = string.ascii_lowercase
        a = random.random()
        if a > 0.3:
            # make letter
            size_current = random.randrange(1, max_size_pattern, 1)
            letter = "".join(random.choice(letters) for _ in range(size_current))
            pattern.append(letter)

            file_1.write(letter + '\n')
            file_2.write(letter + ' ')
        else:
            # make joker
            file_1.write('?' + '\n')
            file_2.write('?' + ' ')

    file_2.write('\n')
    file_1.close()
    file_2.close()

def make_text(size_text, file1, arg1, file2, arg2):
    text = []
    max_size_pattern = size_word

    line = 1
    column = 1

    file_1 = open(file1, arg1)
    file_2 = open(file2, arg2)

    file_1.write(str(size_text) + "\n")

    for iter in range(size_text):
        letters = string.ascii_lowercase
        a = random.random()
        if a > 0.3:
            # same line
            pass
        else:
            # new line
            line = line + 1
            column = 1
            file_2.write('\n')

        size_current = random.randrange(1, max_size_pattern, 1)
        letter = "".join(random.choice(letters) for _ in range(size_current))

        file_1.write(letter + '\n' + str(line) + '\n' + str(column) + '\n')
        file_2.write(letter + ' ')
        column = column + 1

    file_1.close()
    file_2.close()


# main
os.system("rm pattern.txt text.txt test.txt")

patt = input("how many pattern? ")
text = input("how many text? ")

make_pattern(patt, 'pattern.txt', 'w', 'test.txt', 'a')
make_text(text, 'text.txt', 'w', 'test.txt', 'a')
