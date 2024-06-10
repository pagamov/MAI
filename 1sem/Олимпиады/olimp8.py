a = list(map(int,input()))
print(a)
p = 0
for i in range(len(a)):
    if a[i] == 0 or a[i] == 4 or a[i] == 6 or a[i] == 9:
        p += 1
    elif a[i] == 8:
        p += 2
print(p)
