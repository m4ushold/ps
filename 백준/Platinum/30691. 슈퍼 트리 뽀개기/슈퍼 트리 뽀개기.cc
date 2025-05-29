#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;

struct Seg {
    vector<ll> T[sz<<1];
    void bld() { 
        for(int i=sz-1;i>=1;i--) {
            T[i].resize(T[i*2].size()+T[i*2+1].size());
            merge(T[i*2].begin(),T[i*2].end(), T[i*2+1].begin(),T[i*2+1].end(), T[i].begin());
        }
    }
    vector<ll>& operator[](int i) {return T[sz|i];}
    ll qry(int l, int r, ll c) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=upper_bound(T[l].begin(),T[l].end(),c)-T[l].begin(), l++;
            if(~r&1) ret+=upper_bound(T[r].begin(),T[r].end(),c)-T[r].begin(), r--;
        }
        return ret;
    }
} seg;

ll N, K, D[sz], IN[sz], OUT[sz];
vector<pair<ll,ll>> G[sz];

void dfs(int v=1, int p=-1) {
    static int pv = 0;
    IN[v] = ++pv;
    for(auto [i,w]:G[v]) if(i!=p) {
        D[i] = D[v] + w;
        dfs(i,v);
    }
    OUT[v] = pv;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for(ll i=1,a,b,c;i<N;i++) {
        cin >> a >> b >> c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    dfs();
    for(int i=1;i<=N;i++) seg[IN[i]].push_back(D[i]);
    seg.bld();

    ll ans = 0;
    for(int i=1;i<=N;i++) {
        ans = max(ans, seg.qry(IN[i], OUT[i], D[i] + K));
    }
    cout << ans;
    return 0;
}