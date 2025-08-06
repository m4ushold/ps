n,s = map(int,input().split())
v = list()
for i in range(n):
    name,b = input().split()
    b=int(b)
    v.append((b,name))

v=sorted(v)[::-1]

ans=list()
for b,name in v:
    if b<=s:
        ans.append(name)
        s-=b


if s>0:
    ans=[]

print(len(ans))
for i in ans:
    print(i)