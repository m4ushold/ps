#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, M, D[202020], X;
vector<int> G[202020];

void dfs(int v=1) {
    D[v]=1;
    vector<ll> a;
    for(int i:G[v]) {
        dfs(i);
        D[v]=max(D[v],D[i]+1);
        a.push_back(D[i]);
    }
    sort(rall(a));
    if(a.size()>1) X=max(X,a[0]+a[1]+1);
    else if(a.size()==1) X=max(X,a[0]);
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=2;i<=N;i++) {
        int p; cin >> p;
        G[p].push_back(i);
    }
    dfs();
    if(D[1] == N) cout << N*M;
    else cout << X + D[1]*(M-1)*2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}