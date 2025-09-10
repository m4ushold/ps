#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<5, mod = 9'999'991;
ll F[sz]={1}, I[sz], G[sz][2], S[sz];

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n/=2;
    }
    return res;
}

void insert(int v, int x) {
    if(G[v][v < x] == 0) G[v][v < x] = x;
    else insert(G[v][v < x], x);
}

ll dfs(int v) {
    S[v]=1;
    ll res=1;
    for(int i:{0,1}) if(G[v][i]) res = res * dfs(G[v][i]) % mod * I[S[G[v][i]]] % mod, S[v]+=S[G[v][i]];
    return res * F[S[v]-1] % mod;
}

void sol() {
    memset(G, 0, sizeof(G)), memset(S, 0, sizeof(S));
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    for(int i=1;i<n;i++) insert(v[0], v[i]);
    cout << dfs(v[0]) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<sz;i++) F[i] = F[i-1] * i % mod, I[i] = pw(F[i], mod-2);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}