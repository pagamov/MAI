n = int(input())
def fac(n):
    res = 1
    if n == 0 or n == 1:
        return res
    while n != 1:
        res = res * n
        n -= 1
    return res
a = fac(n)
print(a%(10**9 + 7))
