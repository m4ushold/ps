#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, Q;
vector<int> G[202020];
set<int> ST;

int P[303030], S[303030], D[202020], Par[202020];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void dfs(int v=1, int p=-1) {
    for(int i:G[v]) if(i!=p) {
        D[i]=D[v]+1;
        Par[i]=v;
        dfs(i,v);
    }
}

void sol(int tc) {
    cin >> N >> Q;
    init(N);
    vector<pll> v(N);
    pll e;
    for(auto &[a,b]:v) {
        cin >> a >> b;
        if(Union(a,b)) {
            G[a].push_back(b), G[b].push_back(a);
        } else e={a,b};
    }
    dfs();
    ll x=e.first, y=e.second;
    ST.insert(x), ST.insert(y);
    while(x!=y) {
        if(D[x] > D[y]) swap(x,y);
        ST.insert(y);
        y=Par[y];
    }
    if(x) ST.insert(x);

    for(int i=1;i<=N;i++) G[i].clear();
    init(N);
    for(auto [a,b]:v) {
        if(ST.count(a) && ST.count(b)) continue;
        Union(a,b);
    }

    for(int i=0;i<Q;i++) {
        int a,b; cin >> a >> b;
        if(Find(a) == Find(b)) cout << 1 << endl;
        else cout << 2 << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}