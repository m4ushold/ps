#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<20;

struct {
    ll T[sz<<1], C[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]+=x;
        C[i]=T[i]>0;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1], C[i]=C[i*2]+C[i*2+1];
    }
    ll qry(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=T[l++];
            if(~r&1) ret+=T[r--];
        }
        return ret;
    }
    int idx(int i=1, int l=0, int r=sz-1) {
        if(l == r) return l;
        int m = l+r>>1;
        if(C[i*2] == r-m) return idx(i*2+1, m+1, r);
        return idx(i*2,l,m);
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    seg.upd(0,1);
    for(int i=1;i<=n;i++) {
        int a,b; cin >> a >> b;
        if(a==1) seg.upd(b, 1);
        else seg.upd(b,-1);

        cout << seg.qry(1, seg.idx()) << "\n";
    }
    
    return 0;
}