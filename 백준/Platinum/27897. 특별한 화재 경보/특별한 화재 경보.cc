#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<19;
struct Seg {
    ll T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
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
    cin.tie(0)->sync_with_stdio(0);
    ll n,l; cin >> n >> l;
    vector<ll> v(n);
    for(ll &i:v) {
        cin >> i;
        l += seg.qry(i+1, n);
        seg.upd(i, 1);
    }
    l = min(l, n*(n-1)/2);
    cout << l;
    
    return 0;
}