#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;
struct Seg {
    ll T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]+=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
    }
    ll qry(int k) {
        int i=1;
        while(i<sz) {
            if(k<=T[i*2]) i*=2;
            else k-=T[i*2], i=i*2+1;
        }
        return i^sz;
    }
} seg;

void sol(int tc) {
    int n,m; cin >> n >> m;
    for(int i=0,x;i<n;i++) cin >> x, seg.upd(x,1);
    vector<int> w(m), b(m);
    for(int &i:w) cin >> i;
    for(int &i:b) cin >> i;

    for(int i=0;i<m;i++) {
        int x = seg.qry(n-b[i]+1);
        if(x<w[i]) {
            cout << 0;
            return;
        }
        seg.upd(x,-1), seg.upd(x-w[i],1);
    }
    cout << 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}