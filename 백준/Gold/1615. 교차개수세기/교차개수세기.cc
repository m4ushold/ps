#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    const static int sz=1<<17;
    ll T[sz<<1];
    void update(int v, int x) {
        v|=sz, T[v]+=x;
        while(v>>=1) T[v]=T[v*2]+T[v*2+1];
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<pair<int,int>> v(m);
    for(auto &[a,b]:v) cin >> a >> b;
    sort(v.begin(),v.end());
    ll cnt=0;
    for(auto [a,b]:v) {
        cnt+=seg.query(b+1,n);
        seg.update(b,1);
    }
    cout << cnt;
    return 0;
}