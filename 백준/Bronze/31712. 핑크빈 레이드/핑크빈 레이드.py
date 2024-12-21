a = [list(map(int, input().split())) for _ in range(3)]
h = int(input())
s = 0

while 1:
    for x,y in a:
        if s%x == 0:
            h-=y
    if h <= 0:
        print(s)
        break
    else:
        s+=1