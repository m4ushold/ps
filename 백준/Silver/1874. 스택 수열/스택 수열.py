n = int(input())
A = []
s = []  # 스택 대신 리스트 사용

c = 1
idx = 0

for _ in range(n):
    a = int(input())
    
    while c <= a:
        s.append(c)
        A.append('+')
        c += 1
        
    while s and s[-1] == a:
        s.pop()
        A.append('-')

if s:
    print("NO")
else:
    print('\n'.join(A))