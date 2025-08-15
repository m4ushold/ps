#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod = 1e9+7;
ll N, M, Q, A[101010], I[101010], II[101010], D[101010], DD[101010];
vector<int> G[101010], R[101010];

void sol(int tc) {
    cin >> N >> M >> Q;
    for(int i=1;i<=N;i++) cin >> A[i];
    map<pair<int,int>,int> m;
    for(int i=0,u,v;i<M;i++) {
        cin >> u >> v;
        if(A[u] == A[v]) continue;
        if(A[u] > A[v]) swap(u,v);
        G[u].push_back(v), R[v].push_back(u), I[v]++, II[u]++;
        m[{u,v}]=1;
    }

    ll ans=N;
    queue<int> q;
    for(int i=1;i<=N;i++) if(!I[i]) q.push(i);
    while(q.size()) {
        int v = q.front(); q.pop();
        for(int i:G[v]) {
            if(--I[i] == 0) q.push(i);
            D[i]=(D[i]+D[v]+1)%mod;
        }
        ans = (ans + D[v]) % mod;
    }

    for(int i=1;i<=N;i++) if(!II[i]) q.push(i);
    while(q.size()) {
        int v = q.front(); q.pop();
        for(int i:R[v]) {
            if(--II[i] == 0) q.push(i);
            DD[i]=(DD[i]+DD[v]+1)%mod;
        }
    }

    for(int i=1;i<=N;i++) D[i]=(D[i]+1)%mod, DD[i]=(DD[i]+1)%mod;

    for(int i=0,u,v;i<Q;i++) {
        cin >> u >> v;
        if(A[u] == A[v]) {
            cout << ans << '\n';
            continue;
        }
        if(A[u] > A[v]) swap(u,v);
        if(m[{u,v}]) cout << (ans - D[u] * DD[v] % mod + mod) % mod << '\n';
        else cout << (ans + D[u] * DD[v] % mod) % mod << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}