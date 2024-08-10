while True :
    a, b, c = map(int, input().split())
    if a == b == c == 0:
        break
    print((c-a)//b+1 if (c-a)%b==0 and (c-a)//b>=0 else "X")