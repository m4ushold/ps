#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    ll tree[1<<20], sz=1<<19;
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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first, v[i].second=i;
    sort(v.begin(),v.end());
    ll res=0;
    for(auto [x,i]:v) {
        seg.update(i,1);
        res+=seg.query(i+1,n-1);
    }
    cout << res;
    return 0;
}