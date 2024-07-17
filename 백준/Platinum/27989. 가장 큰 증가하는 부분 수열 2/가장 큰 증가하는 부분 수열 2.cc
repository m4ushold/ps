#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, DP[1010101], P[1010101], A[1010101], B[1010101];

struct SegTree {
    int sz=1<<20;
    ll T[1<<21];
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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<ll> v(N);
    for(int i=1;i<=N;i++) cin >> A[i], v[i-1]=A[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;

    for(int i=1;i<=N;i++) {
        ll mx=seg.query(0,A[i]-1);
        seg.update(A[i],mx+v[A[i]-1]);
    }
    cout << seg.query(0,N);
    return 0;
}