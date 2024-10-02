#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 10101;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V], AA[101][101], BB[101][101];
vector<int> G[MAX_V];

bool dfs(int v) {
    vi[v] = 1;
    for (int i: G[v]) {
        if (B[i] == -1 || !vi[B[i]] && dfs(B[i])) {
            A[v] = i, B[i] = v;
            return 1;
        }
    }
    return 0;
}

int matching() {
    int cnt = 0;
    for (int i = 0; i < N * M; i++) {
        for (int i = 0; i < MAX_V; i++) vi[i] = 0;
        cnt += dfs(i);
    }
    return cnt;
}

int idx(int i, int j) {
    return i * M + j;
}

bool bound(int x, int y) {
    return 0 <= min(x, y) && x < N && y < M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < MAX_V; i++) A[i] = B[i] = -1;

    int aa = 0, bb = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> AA[i][j];
            aa += AA[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> BB[i][j];
            if (AA[i][j] && BB[i][j]) {
                AA[i][j] = 0, BB[i][j] = 0;
                aa--;
            }
            bb += BB[i][j];
        }
    }

    if (aa != bb) {
        return cout << -1, 0;
    }

    vector<pair<int, int> > v({
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    });

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (AA[i][j] == 1) {
        for (auto [dx,dy]: v) if (bound(i + dx, j + dy)) {
            int x = i + dx, y = j + dy;
            if (AA[i][j] && BB[x][y]) {
                G[idx(i, j)].push_back(idx(x, y));
            }
        }
    }

    int n = matching();
    cout << (aa - n) * 2 + n;
    return 0;
}
