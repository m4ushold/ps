import sys

def input():
    return sys.stdin.readline().rstrip()

MAX_N = 1011

DP = [[[0] * 2 for _ in range(MAX_N)] for _ in range(MAX_N)]

child = [[0, 0] for _ in range(MAX_N)]

check = [False] * MAX_N

def dfs(cur):
    if child[cur][0] == 0 and child[cur][1] == 0:
        DP[cur][1][0] = 1
        DP[cur][0][1] = 1
        return

    left = child[cur][0]
    right = child[cur][1]

    if left != 0:
        dfs(left)
    if right != 0:
        dfs(right)
    for i in range(1, MAX_N):
        DP[cur][i][0] += DP[left][i - 1][0] * DP[right][i - 1][1]
        DP[cur][i][0] += DP[left][i - 1][0] * DP[right][i - 1][0]
        DP[cur][i][0] += DP[left][i - 1][1] * DP[right][i - 1][1]
        DP[cur][i][0] += DP[left][i - 1][1] * DP[right][i - 1][0]

    for i in range(MAX_N):
        DP[cur][i][1] += DP[left][i][0] * DP[right][i][0]


N = int(input())

for i in range(1, N + 1):
    l, r = map(int, input().split())
    child[i][0] = l
    child[i][1] = r
        
    if l != 0:
        check[l] = True
    if r != 0:
        check[r] = True
    DP[0][0][0] = 1
    root = 0
for i in range(1, N + 1):
    if not check[i]:
        root = i
        break

dfs(root)
ans = 0
for i in range(N + 1):
    ans += DP[root][i][0]
    ans += DP[root][i][1]

print(ans)

