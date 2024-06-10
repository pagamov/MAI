def fiba(n):
    n1 = 0
    n2 = 1
    z = 0
    global i
    i = 0
    
    while n1 < n:
        z = n1
        n1 = n2
        n2 = z + n2
        i += 1
        if n1 == n:
            if i == 0:
                break
            else:
                return i
    if n1 > n:
        return -1

n = int(input())
a = fiba(n)
if i == 0:
    print(0)
else:
    print(a)
