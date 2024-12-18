n,m=map(int,input().split())
for i in range(n):
    for j in range(m):
        if (i+j)&1:
            print('.',end='')
        else:
            print('*',end='')
    print()