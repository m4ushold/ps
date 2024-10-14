n=input()
s=input().split('A')[1:-1]

cnt=0
for i in s:
    if i.count('N') == 1:
        cnt+=1
print(cnt)