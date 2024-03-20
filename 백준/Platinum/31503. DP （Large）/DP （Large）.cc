#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {

    ll T[1<<21], sz=1<<20;
    void clear() {for(int i=0;i<1<<21;i++) T[i]=0;}
    void update(int v, ll x) {
        v|=sz, T[v]=max(T[v],x);
        while(v>>=1) T[v]=max(T[v*2],T[v*2+1]);
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
        }
        return res;
    }
} seg;

int N, Q, A[303030], L[303030], R[303030];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    vector<int> v(N);
    for(int i=1;i<=N;i++) cin >> A[i], v[i-1]=A[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;

    for(int i=1;i<=N;i++) L[i]=seg.query(0,A[i]-1)+1, seg.update(A[i],L[i]);
    seg.clear();
    for(int i=N;i;i--) R[i]=seg.query(A[i]+1,300'000)+1, seg.update(A[i],R[i]);

    int a;
    while(Q--) cin >> a, cout << L[a]+R[a]-1 << '\n';
    return 0;
}