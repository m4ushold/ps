import sys
sys.setrecursionlimit(200000)

N = 0
L = []
R = []
IN = []
D = []

def dfs(v):
    if L[v]:
        dfs(L[v])
    if R[v]:
        dfs(R[v])

    for i in range(N+1):
        D[v][i][0] += D[L[v]][i][1] * D[R[v]][i][1]

        if i > 0:
            D[v][i][1] += (
                D[L[v]][i-1][0] * D[R[v]][i-1][0] +
                D[L[v]][i-1][0] * D[R[v]][i-1][1] +
                D[L[v]][i-1][1] * D[R[v]][i-1][0] +
                D[L[v]][i-1][1] * D[R[v]][i-1][1]
            )

def sol():
    global N, L, R, IN, D
    N = int(sys.stdin.readline())
    L = [0] * (N+1)
    R = [0] * (N+1)
    IN = [0] * (N+1)

    for i in range(1, N+1):
        a, b = map(int, sys.stdin.readline().split())
        L[i], R[i] = a, b
        if a:
            IN[a] += 1
        if b:
            IN[b] += 1

    root = 0
    for i in range(1, N+1):
        if IN[i] == 0:
            root = i
            break

    D = [[[0,0] for _ in range(N+1)] for __ in range(N+1)]
    D[0][0][1] = 1

    dfs(root)

    ans = 0
    for i in range(N+1):
        ans += D[root][i][0] + D[root][i][1]
    print(ans)

if __name__ == "__main__":
    sol()