n=int(input())

cnt=0
for b in range(2,11):
    s=''
    tmp=n
    while tmp>0:
        s=str(tmp%b)+s
        tmp//=b
    if s==s[::-1]:
        print(b,s)
        cnt=1
if cnt==0:
    print("NIE")