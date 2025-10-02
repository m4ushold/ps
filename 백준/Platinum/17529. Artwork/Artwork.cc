#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, K, P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

ll f(ll x, ll y) {
    return x*x+y*y;
}

void sol(int tc) {
    cin >> M >> N >> K;
    init(K+5);
    vector<array<ll,3>> v;
    for(int i=5;i<=5+K;i++) {
        int x,y,r; cin >> x >> y >> r;
        v.push_back({x,y,r});
        if(x-r<=0) Union(i,1);
        if(x+r>=M) Union(i,3);
        if(y-r<=0) Union(i,4);
        if(y+r>=N) Union(i,2);
    }
    for(int i=0;i<K;i++) for(int j=i+1;j<K;j++) {
        auto [x1,y1,r1]=v[i];
        auto [x2,y2,r2]=v[j];
        if(f(x1-x2,y1-y2) <= (r1+r2)*(r1+r2)) {
            Union(i+5,j+5);
        }
    }

    if(Find(1)==Find(3) || Find(2) == Find(4) || Find(2) == Find(3) || Find(1) == Find(4)) cout << "N";
    else cout << "S";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}