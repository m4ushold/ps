a=list(map(int, input().split()))
b=list(map(int, input().split()))
c,d=0,0
for i in range(10):
    if a[i]>b[i]: c += 1
    elif a[i]<b[i]: d += 1
if c>d:
    print('A')
elif c<d:
    print('B')
else:
    print('D')