n,k = map(int,input().split())

kk,kkk=k%10, (2*k)%10
a=[]

for i in range(1,n+1):
    if i%10 != kk and i%10 != kkk:
        a.append(str(i))
print(len(a))
print(' '.join(a))