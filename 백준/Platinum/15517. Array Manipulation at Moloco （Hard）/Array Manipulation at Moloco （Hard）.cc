#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    const static int sz=1<<20;
    ll T[sz<<1];
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

int N, A[1010101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<int> v(N);
    for(int i=1;i<=N;i++) cin >> A[i], v[i-1]=A[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;

    for(int i=1;i<=N;i++) {
        seg.update(A[i],1);
        cout << seg.query(1,A[i]-1) << '\n';
    }
    return 0;
}