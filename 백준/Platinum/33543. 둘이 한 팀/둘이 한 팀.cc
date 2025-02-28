#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<18;
struct Seg {
    ll T[sz<<1];
    void bld() { for(int i=sz-1;i>=1;i--) T[i]=T[i*2]+T[i*2+1]; }
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
    }
    ll& operator[](int i) {return T[sz|i];}
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
    ll n; cin >> n;
    ll team=0;
    vector<pair<ll,ll>> v(n);
    
    vector<ll> diff;
    for(auto &[l,r]:v) cin >> l >> r, team += max(l,r), diff.push_back(l-r);
    sort(v.begin(),v.end()), sort(diff.begin(),diff.end());
    for(int i=0;i<n;i++) seg.upd(i, diff[i]);

    ll delta=0;

    int q; cin >> q;
    for(ll i=1,x;i<=q;i++) {
        char op; cin >> op >> x;
        
        if(op == 'A') {
            ll j = lower_bound(diff.begin(),diff.end(),-delta) - diff.begin(), cnt = n-j;
            team += cnt * x;

            ll l = -x+1-delta, r = -delta-1; // diff closed range
            ll lidx = lower_bound(diff.begin(),diff.end(),l)-diff.begin(), ridx = upper_bound(diff.begin(),diff.end(),r)-diff.begin()-1;
            if(lidx <= ridx) {
                ll len = ridx - lidx + 1;
                team += seg.qry(lidx, ridx) + len*delta + len*x;
            }

            delta += x;
        } else {
            ll j = upper_bound(diff.begin(),diff.end(),-delta) - diff.begin(), cnt = max(j, 0LL);
            team += cnt * x;

            ll l = 1-delta, r = -delta+x-1; // diff closed range
            ll lidx = lower_bound(diff.begin(),diff.end(),l)-diff.begin(), ridx = upper_bound(diff.begin(),diff.end(),r)-diff.begin()-1;
            if(lidx <= ridx) {
                ll len = ridx - lidx + 1;
                team += abs(seg.qry(lidx, ridx) + len*delta - len*x);
            }
            
            delta -= x;
        }
        cout << team << '\n';
    }
    return 0;
}