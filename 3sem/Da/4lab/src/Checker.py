import random
import os, sys
import string
import subprocess
import time

class Letter(object):
    def __init__(self, letter, line, column):
        self.letter = letter
        self.line = line
        self.column = column
        self.overlap = 0
    def print_(self):
        print(self.letter + " " + str(self.line) + " " + str(self.column))

def read_pattern(file):
    pattern = []
    file_1 = open(file, "r")
    for var in range(int(file_1.readline())):
        pattern.append((file_1.readline()).replace("\n", ""))
    file_1.close()
    return pattern

def read_text(file):
    text = []
    file_1 = open(file, "r")
    for var in range(int(file_1.readline())):
        text.append(Letter(file_1.readline().replace("\n", ""), int(file_1.readline()), int(file_1.readline())))
    file_1.close()
    return text

def find_overlap(pattern, text):
    file = open("check_py.txt", "w")
    for pos_pattern in range(len(pattern)):
        for pos_text in range(len(text)):
            if pattern[pos_pattern] == text[pos_text].letter or pattern[pos_pattern] == "?":
                if (pos_text - pos_pattern >= 0):
                    text[pos_text - pos_pattern].overlap += 1
    for let in text:
        if let.overlap == len(pattern):
            file.write(str(let.line) + ", " + str(let.column) + '\n')
    file.close()

# main
p = read_pattern("pattern.txt")
t = read_text("text.txt")
find_overlap(p, t)

os.system("./main < test.txt > check_cpp.txt")
os.system("diff check_cpp.txt check_py.txt")
