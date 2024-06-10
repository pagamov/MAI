var = list(map(int,input().split()))
a = list(input())
b = list(input())
suma = 0
for i in range(0, len(a) - len(b) + 1):
    if b[0] == a[i]:
        if (i + len(b)) > len(a):
            break
        else:
            for j in range(0,len(b)):
                if b[j] != a[i + j]:
                    suma -= 1
                    break
            suma += 1
        
print(suma)
