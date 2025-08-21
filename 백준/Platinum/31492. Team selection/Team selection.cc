#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<22;
struct Seg {
    ll T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
    }
    ll qry(int k) {
        int i=1;
        while(i<sz) {
            if(T[i*2]>=k) i<<=1;
            else k-=T[i*2], i=i<<1|1;
        }
        return i^sz;
    }
} seg;

void sol(int tc) {
    int n; cin >> n;
    for(int i=1;i<=n;i++) seg.upd(i,1);
    vector<int> a(n/2), b(n/2), aa, bb;
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;

    for(int i=0;i<n/2;i++) {
        int x = seg.qry(a[i]);
        seg.upd(x,0);
        aa.push_back(x);
        
        x = seg.qry(b[i]);
        seg.upd(x,0);
        bb.push_back(x);
    }
    for(int i:aa) cout << i << ' ';
    cout << '\n';
    for(int i:bb) cout << i << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}