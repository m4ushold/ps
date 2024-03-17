#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    ll T[1<<20], sz=1<<19;
    void init() { for(int i=0;i<sz*2;i++) T[i]=0; }
    void update(int v, int x) {
        v|=sz, T[v]=x;
        while(v>>=1) T[v]=T[v*2]+T[v*2+1];
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz, r|=sz;l<=r;l/=2, r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;

int A[505050];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n && n) {
        seg.init();
        vector<int> v(n);
        for(int i=1;i<=n;i++) cin >> A[i], v[i-1]=A[i];
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()), v.end());
        for(int i=1;i<=n;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;
        ll res=0;
        for(int i=1;i<=n;i++) {
            seg.update(A[i],1);
            res+=seg.query(A[i]+1,n);
        }
        cout << res << '\n';
    }
    
    return 0;
}