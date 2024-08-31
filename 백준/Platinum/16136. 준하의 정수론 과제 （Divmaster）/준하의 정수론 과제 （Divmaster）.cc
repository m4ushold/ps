#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, Q, A[1010101];

struct Seg {
    static const int sz=1<<17;
    ll T[sz<<1], M[sz<<1];
    void build() {for(int i=sz-1;i;i--) T[i]=T[i*2]+T[i*2+1], M[i]=max(M[i*2],M[i*2+1]);}
    void update(int l, int r, int i=1, int s=0, int e=sz-1) {
        if(r<s || e<l) return;
        if(s==e) {M[i] = T[i] = A[T[i]]; return;}
        int m=s+e>>1;
        if(M[i*2] > 2) update(l,r,i*2,s,m);
        if(M[i*2+1] > 2) update(l,r,i*2+1,m+1,e);
        T[i]=T[i*2]+T[i*2+1], M[i]=max(M[i*2],M[i*2+1]);
    }
    ll qry(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=T[l++];
            if(~r&1) ret+=T[r--];
        }
        return ret;
    }
} seg;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<=1'000'000;i++) for(int j=i;j<=1'000'000;j+=i) A[j]++;

    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> seg.T[seg.sz|i], seg.M[seg.sz|i]=seg.T[seg.sz|i];
    seg.build();
    for(int i=0,o,l,r;i<Q;i++) {
        cin >> o >> l >> r;
        if(o==1) seg.update(l,r);
        else cout << seg.qry(l,r) << '\n';
    }
    return 0;
}