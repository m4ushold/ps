for _ in range(int(input())):
    input()
    n,m=map(int,input().split())
    a=[]
    cnt=0
    for _ in range(n):
        s=input()
        cnt+=s.count('>o<')
        t=''
        for i in s:
            if i=='>':
                t+='v'
            elif i=='<':
                t+='^'
            elif i=='^':
                t+='<'
            elif i=='v':
                t+='>'
            else :
                t+=i
        a.append(t)
    a= [''.join(list(row)) for row in zip(*a)]
    
    for s in a:
        cnt+=s.count('>o<')
    print(cnt)