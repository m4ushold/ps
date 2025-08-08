#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=1<<17;
struct Seg {
    ll T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]+=x;
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

void sol(int tc) {
    int n,s; cin >> n >> s;
    vector<ll> v(n), a;
    for(ll &i:v) cin >> i;
    a=v;
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(ll &i:v) i=lower_bound(a.begin(),a.end(),i)-a.begin();

    ll ans=0, mx=0;
    for(int i=0;i<s;i++) {
        ans+=seg.qry(0,v[i]-1);
        seg.upd(v[i],1);
    }
    mx=ans;
    for(int i=s;i<n;i++) {
        ans -= seg.qry(v[i-s]+1,sz-1);
        seg.upd(v[i-s],-1);
        ans += seg.qry(0,v[i]-1);
        seg.upd(v[i],1);
        mx=max(mx,ans);
    }
    cout << mx << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}