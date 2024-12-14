a=[int(i) for i in input()]
n,dap=len(a),0

b=[0]*(n+1)
for i in range(1,n+1):
    b[i]=b[i-1]+a[i-1]
    
for l in range(2, n+1, 2):
    for i in range(n-l+1):
        m=i + l//2
        aa,bb=b[m]-b[i],b[i+l]-b[m]
        if aa==bb:
            dap=max(dap,l)
print(dap)