#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<20;
int P[sz], S[sz], A[sz];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,k; cin >> n >> m >> k;
    init(n);
    vector<pair<int,int>> v;
    for(int i=1,w;i<=n;i++) cin >> w, v.push_back({w,i});
    sort(v.begin(),v.end());

    for(int i=0,u,v;i<m;i++) {
        cin >> u >> v;
        if(abs(u-v)>1) A[max(u,v)]=1;
        else A[min(u,v)]=1;
    }
    for(int i=1;i<=n;i++) if(!A[i]) Union(i,i==n ? 1 : i+1);

    if(S[Find(1)]==n) return cout << "YES", 0;

    for(auto [w,i]:v) {
        if(Union(i,0)) k-=w;
        if(k<0 || S[Find(1)]==n) break;
    }
    cout << (k<0 || S[Find(1)]<n ? "NO" : "YES");
    return 0;
}