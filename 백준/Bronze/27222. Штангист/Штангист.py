n = int(input())
d = list(map(int, input().split()))
g = 0

for i in range(n):
    x, y = map(int, input().split())
    t = y - x
    
    if d[i] == 1 and t > 0:
        g += t

print(g)