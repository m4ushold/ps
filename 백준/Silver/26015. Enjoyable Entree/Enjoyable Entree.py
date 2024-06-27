from decimal import *
 
 
def mul(a, b):
    n = len(a)
    c = [[Decimal(0) for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                c[i][j] += a[i][k] * b[k][j]
 
    return c
 
 
n = int(input())
n -= 2
 
if n < 0:
    print(100, 0)
    exit(0)
 
r = [[Decimal(1), Decimal(0)], [Decimal(0), Decimal(1)]]
a = [[Decimal(0.5), Decimal(1)], [Decimal(0.5), Decimal(0)]]
 
while n:
    if n & 1: r = mul(r, a)
    a = mul(a, a)
    n = n >> 1
 
print(r[1][0] * 100, r[0][0] * 100)