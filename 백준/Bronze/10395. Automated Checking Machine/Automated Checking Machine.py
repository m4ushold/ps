a,b = [list(map(int,input().split())) for _ in range(2)]
print('Y' if sum([i^j for i,j in zip(a,b)]) == 5 else 'N')