#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 1<<19;
int N, M, P[sz], S[sz];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

set<int> G[sz];

void sol(int tc) {
    cin >> N >> M;
    init(N);
    vector<pll> v;
    for(int i=1;i<=M;i++) {
        int a,b; char c;
        cin >> a >> b >> c;
        if(c == 'T') Union(a,b);
        else v.push_back({a,b});
    }

    int cnt=0;
    for(int i=1;i<=N;i++) if(i==Find(i)) cnt++;
    for(auto [a,b]:v) {
        a=Find(a), b=Find(b);
        if(a==b) continue;
        G[a].insert(b), G[b].insert(a);
    }

    int ans=0;
    for(int i=1;i<=N;i++) if(i==Find(i) && G[i].size() == cnt-1) ans+=S[i];
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}