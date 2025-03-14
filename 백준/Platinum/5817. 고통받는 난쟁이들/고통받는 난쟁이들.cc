#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<18;
struct Seg {
    pair<ll,ll> T[sz<<1];
    pair<ll,ll> f(pair<ll,ll> a, pair<ll,ll> b) {
        return {min(a.first,b.first),max(a.second,b.second)};
    }
    void upd(int i, pair<ll,ll> x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=f(T[i*2],T[i*2+1]);
    }
    pair<ll,ll> qry(int l, int r) {
        pair<ll,ll> res={1e9,0};
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res=f(res,T[l++]);
            if(~r&1) res=f(res,T[r--]);
        }
        return res;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<int> v(n+1), idx(n+1);
    for(int i=0;i<sz;i++) seg.upd(i,{1e9,0});
    for(int i=1,x;i<=n;i++) cin >> v[i], seg.upd(v[i], {i,i}), idx[v[i]]=i;

    for(int i=1;i<=m;i++) {
        int a,b,c; cin >> a >> b >> c;
        if(a==1) {
            int d=idx[v[b]], e=idx[v[c]];
            seg.upd(v[b],{e,e}), seg.upd(v[c],{d,d});
            swap(idx[v[b]],idx[v[c]]);
            swap(v[b],v[c]);
        } else {
            auto [mn,mx]=seg.qry(b,c);
            if(c-b == mx-mn) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}