while 1:
    a,b = map(int,input().split())
    if a+b==0: break
    print(min([a*i+b*j for i,j in [[30,40],[35,30],[40,20]]]))