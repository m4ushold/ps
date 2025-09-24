#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int mod = 1e9+7;
int N, M, IN[2020], D[2020], A[2020];
vector<int> G[2020];

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=M;i++) {
        int n; cin >> n;
        for(int j=1;j<=n;j++) {
            int x; cin >> x;
            G[i].push_back(x);
            IN[x]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=N;i++) if(!IN[i]) q.push(i);
    D[1]=1, A[1]=1;
    while(q.size()) {
        int v = q.front(); q.pop();
        for(int i:G[v]) {
            D[i]=(D[v]+D[i])%mod;
            A[i]|=A[v];
            if(--IN[i] == 0) q.push(i);
        }
    }

    ll ans=0, cnt=0;
    for(int i=M+1;i<=N;i++) {
        ans=(ans+D[i])%mod, cnt+=A[i];
    }
    cout << ans << ' ' << cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}