#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, M, vi[55], D[55], P[55];
vector<tuple<ll,ll,ll>> E;

void Init(int n) { for(int i=1;i<=n;i++) P[i]=i;}
int Find(int v) { return P[v]==v? v: P[v]=Find(P[v]); }
bool Union(int u, int v) { return Find(u)!=Find(v) && (P[P[u]]=P[v], true); }

ll kruskal()
{
    ll ret=0;
    Init(N);
    sort(E.begin(),E.end());
    for(auto [w,u,v]:E) if (Union(u,v)) ret+=w;
    return ret;
}

int f(char c) {
    if(islower(c)) return c-'a'+1;
    else if(isupper(c)) return c-'A'+27;
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        char c; cin >> c;
        if(f(c)) E.emplace_back(f(c),i,j);
        M+=f(c);
    }
    
    ll res=kruskal(), cnt=0;
    for(int i=1;i<=N;i++) if(i==P[i]) ++cnt;
    if(cnt>1) cout << -1;
    else cout << M-res;
    return 0;
}