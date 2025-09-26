#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol(int tc) {
    int n,q; cin >> n >> q;
    init(n);
    vector<array<int,3>> x,y;
    for(int i=1;i<=n;i++) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        x.push_back({x1,x2,i}), y.push_back({y1,y2,i});
    }
    sort(x.begin(),x.end()), sort(y.begin(),y.end());
    int p=-1e9-1, pp=0;
    for(auto [s,e,i]:x) {
        if(s<=p) Union(pp, i);
        p=max(p,e), pp=i;
    }
    p=-1e9-1, pp=0;
    for(auto [s,e,i]:y) {
        if(s<=p) Union(pp, i);
        p=max(p,e), pp=i;
    }

    for(int i=0,a,b;i<q;i++) {
        cin >> a >> b;
        cout << (Find(a) == Find(b)) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}