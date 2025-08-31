#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 1<<20;
struct {
    pll T[sz<<1];
    pll op(pll a, pll b) {
        if(a.first < b.first) swap(a,b);
        return {a.first, max(a.second, b.first)};
    }
    void upd(int i, ll x) {
        T[i|=sz].first += x;
        while(i/=2) T[i]=op(T[i<<1],T[i<<1|1]);
    }
    pll qry(int l, int r) {
        pll res;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res=op(res,T[l++]);
            if(~r&1) res=op(res,T[r--]);
        }
        return res;
    }
} seg, seg2;


vector<pll> Y[sz], X[sz];
ll YS[sz], XS[sz];

void sol(int tc) {
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        int x,y,v; cin >> x >> y >> v;
        seg.upd(x,v);
        seg2.upd(y,v);
        Y[y].push_back({x,v});
        X[x].push_back({y,v});
        YS[y]+=v;
        XS[x]+=v;
    }

    vector<ll> vec;
    vec.push_back(0), vec.push_back(0);
    ll mx=0;
    for(int i=0;i<sz;i++) if(Y[i].size()) {
        vec.push_back(YS[i]);
        ll sum=0;
        for(auto [x,v]:Y[i]) sum+=v, seg.upd(x,-v);
        sum += seg.T[1].first + seg.T[1].second;
        for(auto [x,v]:Y[i]) seg.upd(x,v);
        mx=max(mx,sum);
    }
    sort(vec.begin(),vec.end());
    int s = vec.size();
    mx=max(mx,vec[s-1]+vec[s-2]+vec[s-3]);

    vec.clear();
    vec.push_back(0),vec.push_back(0);
    for(int i=0;i<sz;i++) if(X[i].size()) {
        vec.push_back(XS[i]);
        ll sum=0;
        for(auto [y,v]:X[i]) sum+=v, seg2.upd(y,-v);
        sum += seg2.T[1].first + seg2.T[1].second;
        for(auto [y,v]:X[i]) seg2.upd(y,v);
        mx=max(mx,sum);
    }
    sort(vec.begin(),vec.end());
    s = vec.size();
    mx=max(mx,vec[s-1]+vec[s-2]+vec[s-3]);;

    cout << mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}