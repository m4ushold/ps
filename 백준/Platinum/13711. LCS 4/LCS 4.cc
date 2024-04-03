#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    ll T[1<<21], sz=1<<20;
    void clear() { for(int i=0;i<sz*2;i++) T[i]=0; }
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

int N, DP[101010], A[101010], B[101010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,a;i<=N;i++) cin >> a, A[a]=i;
    for(int i=1,a;i<=N;i++) cin >> a, B[i]=A[a];

    for(int i=1,a;i<=N;i++) DP[i]=seg.query(0,B[i]-1)+1, seg.update(B[i],DP[i]);
    cout << *max_element(DP,DP+N+1);
    return 0;
}