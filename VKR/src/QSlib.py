import decimal
import numpy as np
def GCD(m,n):
    mult = 1
    if m > n:
        m = m % n
    elif n > m:
        n = n % m

    while True:
        if m == 0 or n == 0 or m == n:
            return mult*max(n,m)
        if m == 1 or n == 1:
            return mult

        mm2 = m % 2
        nm2 = n % 2
        if mm2 == 0 and nm2 == 0:
            mult *= 2
            m = m//2
            n = n//2
        elif mm2 == 0 and nm2 != 0:
            m = m//2
        elif mm2 != 0 and nm2 == 0:
            n = n//2
        elif mm2 != 0 and nm2 != 0:
            if n > m:
                piv = (n-m)//2
                n = m
                m = piv
            elif n < m:
                m = (m-n)//2
                
class Q:
    def __init__(self,n):
        self.n = n
        self.m = int(decimal.Decimal(n).sqrt() + 1)
    def __call__(self,x):
        return (x + self.m)**2 - self.n
    
def legendre(a, p):
    return pow(a, (p - 1) // 2, p)

def tonelli(n, p):
    assert legendre(n, p) == 1, "not a square (mod p)"
    q = p - 1
    s = 0
    while q % 2 == 0:
        q //= 2
        s += 1
    if s == 1:
        return pow(n, (p + 1) // 4, p)

    z = 2
    for z in range(2, p):
        if p - 1 == legendre(z, p):
            break
    c = pow(z, q, p)
    r = pow(n, (q + 1) // 2, p)
    t = pow(n, q, p)
    m = s
    t2 = 0
    while (t - 1) % p != 0:
        t2 = (t * t) % p
        for i in range(1, m):
            if (t2 - 1) % p == 0:
                break
            t2 = (t2 * t2) % p
        b = pow(c, 1 << (m - i - 1), p)
        r = (r * b) % p
        c = (b * b) % p
        t = (t * c) % p
        m = i
    return r



def smooth_region(L1, L2, q, primes):
    res0 = list(range(L1, L2))
    res1 = np.array([q(x) for x in range(L1, L2)])
    res2 = np.zeros((len(res0), len(primes)), dtype="int8")

    s = [[] for _ in range(len(primes.r))]
    for smooth_idx, prime in enumerate(primes):
        for r in primes.r[smooth_idx]:
            k = L1 // prime
            while r + k*prime >= L1:
                k -= 1
            k+=1
            s[smooth_idx].append(r + k*prime)

    for prime_idx, prime in enumerate(primes):
        for s_i in s[prime_idx]:
            if s_i < L2:
                # гарантируем что начиная с s_1 - L1, каждое число через prime
                # делится на этот prime хотя бы 1 раз
                res2[s_i - L1::prime, prime_idx] += 1
                res1[s_i - L1::prime] //= prime
                # дальнешее деление проверяется вручную
                for smooth_idx in range(s_i, L2, prime):
                    x = smooth_idx - L1
                    while res1[x] % prime == 0:
                        res1[x] //= prime
                        res2[x, prime_idx] += 1

    ans = []
    for smooth_idx, qx in enumerate(res1):
        if abs(qx) == 1:
            ans.append([res0[smooth_idx],q(res0[smooth_idx]),np.copy(res2[smooth_idx])])
            
    return ans
