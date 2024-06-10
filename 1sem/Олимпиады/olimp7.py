n = int(input())
polk = [0]*n
num = [0]*n
for p in range(n):
    a = int(input())
    polk[p] = list(map(int, input().split()))
    num[p] = 0
    u = 1 
    while u < len(polk[p]):
        for i in range(len(polk[p])-u):
            if polk[p][i] > polk[p][i+1]:
                polk[p][i],polk[p][i+1] = polk[p][i+1],polk[p][i]
                num[p] += 1
        u += 1
for i in range(n):
    print(num[i])
    
