#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    init(N);
    vector<tuple<int,int,int>> v;
    for(int i=1,a,b,c;i<N;i++) {
        cin >> a >> b >> c;
        v.push_back({c,a,b});
    }
    sort(v.begin(),v.end(),greater<>());

    ll dap=LLONG_MIN/2;
    for(auto [w,s,e]:v) {
        Union(s,e);
        dap=max(dap,(ll)(S[Find(s)]-1)*w);
    }
    cout << dap;
    return 0;
}