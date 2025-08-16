n=int(input())

lo = 0
hi = 1000000
while lo + 1 < hi:
    mid = (lo + hi) // 2

    if (pow(6, mid) <= n):
        lo = mid
    else:
        hi = mid

print(lo+1)