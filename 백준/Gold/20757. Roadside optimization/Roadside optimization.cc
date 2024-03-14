#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, M, vi[10101], D[10101], P[10101];
vector<tuple<ll,ll,ll>> E;

void Init(int n) { for(int i=1;i<=n;i++) P[i]=i;}
int Find(int v) { return P[v]==v? v: P[v]=Find(P[v]); }
bool Union(int u, int v) { return Find(u)!=Find(v) && (P[P[u]]=P[v], true); }

ll kruskal()
{
    ll ret=0;
    Init(N);
    sort(E.begin(),E.end());
    for(auto [w,u,v]:E) if(Union(u,v)) ret+=w;
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> N;
        E.clear();
        int cnt=0;
        for(int i=1;i<=N;i++) for(int j=1,a;j<=N;j++) {
            cin >> a;
            cnt+=a;
            if(a && i!=j) E.emplace_back(a,i,j);
        }
        cout << kruskal() << '\n';
    }
    return 0;
}