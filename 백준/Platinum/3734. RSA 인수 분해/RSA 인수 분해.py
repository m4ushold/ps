import math
n,k = map(int, input().split())
i = max(2, math.isqrt(n//k)-int(1e5))
while True:
    if n%i == 0:
        print(i,'*',n//i)
        break
    i+=1