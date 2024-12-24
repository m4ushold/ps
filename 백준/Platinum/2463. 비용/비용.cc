#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9;
ll P[101010], S[101010];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<array<ll,3>> v(m);
    ll dap=0,sum=0,tot=0;
    for(auto &[w,u,v]:v) cin >> u >> v >> w, tot+=w;
    sort(v.begin(),v.end(),greater<>());
    for(auto &[w,u,v]:v) {
        sum+=w;
        w=tot-sum+w;
    }
    init(n);
    for(auto [w,u,v]:v) {
        u=Find(u), v=Find(v);
        if(u^v) {
            dap+=S[u]*S[v]*w;
            dap%=MOD;
            Union(u,v);
        }
    }
    cout << dap;
    return 0;
}