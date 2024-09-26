#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Seg {
    static const ll sz=1<<17;
    ll T[sz<<1];
    ll f(ll a, ll b){return a+b;}
    void upd(ll i, ll x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=f(T[i*2],T[i*2+1]);
    }
    ll qry(ll l, ll r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=f(ret,T[l++]);
            if(~r&1) ret=f(ret,T[r--]);
        }
        return ret;
    }
} seg;

ll N, IN[101010], OUT[101010], A[101010];
vector<ll> G[101010];
vector<pair<int,int>> V[101010];

void dfs(ll v, ll p=-1) {
    static ll pv=0;
    IN[v]=++pv;
    for(ll i:G[v]) dfs(i,v);
    OUT[v]=pv;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll rt;
    cin >> N;
    vector<tuple<ll,ll,ll>> v;
    for(ll i=1,m,r,p;i<=N;i++) {
        cin >> m >> r >> p;
        if(m>0) G[m].push_back(i);
        else rt=i;
        V[r].emplace_back(p,i);
    }
    dfs(rt);
    for(int i=1;i<=100'000;i++) {
        for(auto [p,j]:V[i]) A[j]=seg.qry(IN[j], OUT[j]);
        for(auto [p,j]:V[i]) seg.upd(IN[j],p);
    }
    
    for(ll i=1;i<=N;i++) cout << A[i] << '\n';
    return 0;
}