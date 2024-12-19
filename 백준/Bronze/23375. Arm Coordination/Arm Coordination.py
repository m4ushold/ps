x, y = map(int, input().split())
r = int(input())

for [i,j] in [[-1,1],[1,1],[1,-1],[-1,-1]]:
    print(x+r*i, y+r*j)