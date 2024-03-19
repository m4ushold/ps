#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    const static int sz=1<<18;
    ll T[sz<<1];
    void build() { for(int i=sz-1;i>=1;i--) T[i]=T[i*2]+T[i*2+1]; }
    void update(int v, int x) {
        v|=sz, T[v]=x;
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

int A[202020];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> A[i];

    for(int i=1;i<=n;i++) seg.T[seg.sz|i] = A[i-1]!=A[i];
    seg.build();
    
    for(int i=1;i<=q;i++) {
        int a,b,c; cin >> a >> b >> c;
        if(a&1) {
            seg.update(b,A[b-1]!=c);
            seg.update(b+1,c!=A[b+1]);
            A[b]=c;
        }
        else cout << seg.query(b,c) + (seg.query(b,b)==0) << '\n';
    }
    return 0;
}