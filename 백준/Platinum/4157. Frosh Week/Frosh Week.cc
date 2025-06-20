#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    ll tree[1<<21], sz=1<<20;
    void update(int v, int x) {
        v|=sz, tree[v]=x;
        while(v>>=1) tree[v]=tree[v*2]+tree[v*2+1];
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz, r|=sz;l<=r;l/=2, r/=2) {
            if(l&1) res+=tree[l++];
            if(~r&1) res+=tree[r--];
        }
        return res;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> v(n), a;
    for(ll &i:v) cin >> i;
    a=v;
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(ll &i:v) i = lower_bound(a.begin(),a.end(),i)-a.begin();

    ll res=0;
    for(ll i:v) {
        seg.update(i,1);
        res+=seg.query(i+1,n);
    }
    cout << res;
    return 0;
}