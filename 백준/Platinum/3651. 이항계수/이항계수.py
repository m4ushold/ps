import math

m = int(input())
ans = []

def bin(x, k):
    l, r = k, x
    while l<=r:
        mid = (l+r)//2
        c = math.comb(mid, k)
        if c == x:
            return mid
        elif c > x:
            r=mid-1
        else:
            l=mid+1
    return 0

for i in range(1,31):
    x = bin(m, i)
    if x > 0:
        ans.append((x,i))
        ans.append((x,x-i))

ans = sorted(list(set(ans)))

print(len(ans))
for n,k in ans:
    print(n,k)