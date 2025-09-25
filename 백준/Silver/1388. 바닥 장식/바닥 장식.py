n,m=map(int,input().split())
ma = [input() for _ in range(n)]

ans=0
for i in ma:
    for j in i.split('|'):
        if len(j)>0:
            ans+=1

mb = []
for i in range(m):
    mb.append('')
    for j in range(n):
        mb[-1]+=ma[j][i]

for i in mb:
    for j in i.split('-'):
        if len(j)>0:
            ans+=1

print(ans)