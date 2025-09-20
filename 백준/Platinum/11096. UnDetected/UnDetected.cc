#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol(int tc) {
    cin >> N;
    vector<array<int,3>> v;
    init(N+1);
    for(int i=0,x,y,r;i<N;i++) {
        cin >> x >> y >> r;
        if(x-r<=0) Union(i+1,0);
        if(x+r>=200) Union(N+1,i+1);
        for(int j=0;j<v.size();j++) {
            auto [xx,yy,rr]=v[j];
            if(hypot(x-xx,y-yy) <= r+rr) Union(i+1,j+1);
        }
        v.push_back({x,y,r});

        if(Find(0) == Find(N+1)) {
            cout << i;
            return;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}