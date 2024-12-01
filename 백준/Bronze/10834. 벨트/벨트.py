a,b = 0,1
for _ in range(int(input())):
    num = list(map(int,input().split()))
    b = b * num[1]//num[0]
    a = (a + num[2]) % 2
print(a, b)