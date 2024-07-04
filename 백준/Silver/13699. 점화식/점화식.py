n=int(input())
a=[0]*(n+1)
a[0]=1

for i in range(1,n+1):
    for j in range(i):
        a[i]+=a[j]*a[i-j-1]

print(a[n])