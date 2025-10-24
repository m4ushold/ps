#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, A[101010], B[101010];
vector<pll> G[101010];

void dfs(int v, int f=0, int p=-1) {
    for(auto [i,w]:G[v]) if(i!=p) {
        if(f) B[i]=B[v]+w;
        else A[i]=A[v]+w;
        dfs(i, f, v);
    }
}

void sol(int tc) {
    cin >> N;
    for(int i=1;i<N;i++) {
        ll a,b,w; cin >> a >> b >> w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    dfs(1);
    int x=1,y=1;
    for(int i=1;i<=N;i++) if(A[x] < A[i]) x=i;
    A[x]=0;
    dfs(x);
    for(int i=1;i<=N;i++) if(A[y] < A[i]) y=i;
    dfs(y,1,-1);
    for(int i=1;i<=N;i++) cout << max(A[i],B[i]) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}