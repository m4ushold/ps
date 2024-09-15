#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    ll T[1<<20], sz=1<<19;
    void build() { for(int i=sz-1;i>=1;i--) T[i]=T[i*2]+T[i*2+1]; }
    void update(int v, int x) {
        v|=sz, T[v]=x;
        while(v>>=1) T[v]=T[v*2]+T[v*2+1];
    }
    ll kth(ll k) {
        int i=1;
        while(i<sz) {
            if(T[i*2]>=k) i*=2;
            else k-=T[i*2], i=i*2+1;
        }
        return i^sz;
    }
} seg;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) seg.T[seg.sz|i]=1;
    seg.build();
    vector<int> v(n+1), ans(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    for(int i=n,a;i;i--) {
        a=seg.kth(seg.T[1]-v[i]);
        seg.update(a,0);
        v[i]=ans[i]=a;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) if(i!=v[i]) return cout << "NIE", 0;
    for(int i=1;i<=n;i++) cout << ans[i] << '\n';
    return 0;
}