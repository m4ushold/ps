n,k = map(int,input().split())
a = list(map(int, input().split(',')))

for _ in range(k):
    t = [0] * (len(a)-1)
    for i in range(len(a)-1):
        t[i] = a[i+1]-a[i]
    a = t
print(','.join([str(i) for i in a]))