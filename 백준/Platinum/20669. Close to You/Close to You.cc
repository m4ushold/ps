#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;

constexpr int mod = 1e9 + 7;
int N, M, K, P, Q;
mat G;

mat operator*(mat &a, mat b) {
    mat res(N, vector<ll>(N));
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) for(int k = 0 ; k < N ; k++) {
        res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mod) % mod;
    }
    return res;
}

mat pw(mat m, ll n) {
    mat res(N, vector<ll>(N));
    for(int i = 0; i < N; i++) res[i][i] = 1;
    while(n) {
        if(n & 1) res = res * m;
        m = m * m, n /= 2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    N+=2;
    G = mat(N, vector<ll>(N));
    for(int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        G[u][v]++, G[v][u]++;
    }

    cin >> P >> Q;
    vector<int> a(P), b(Q);
    for(int &p : a) cin >> p, G[0][p]=1;
    for(int &q : b) cin >> q, G[q][N-1]=1;
    G[N-1][N-1] = 1;
    auto aa = pw(G, K+2), bb = pw(G, 2);
    cout << (aa[0][N-1]-bb[0][N-1]+mod)%mod;
    return 0;
}