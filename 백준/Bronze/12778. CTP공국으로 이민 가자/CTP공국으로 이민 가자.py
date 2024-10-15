for _ in range(int(input())):
    c = input().split()[1]
    if c == "C" :
        print(*[str(ord(i)-ord('A')+1) for i in input().split()])
    else :
        print(*[chr(int(i)+ord('A')-1) for i in input().split()])