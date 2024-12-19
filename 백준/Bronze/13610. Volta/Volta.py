a,b = map(int,input().split())
dap=1
while 1:
    if b*dap - a*dap >= b:
        break
    dap+=1
print(dap)