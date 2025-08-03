#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<19;
struct EKA {
    ll T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=max(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=max(ret,T[l++]);
            if(~r&1) ret=max(ret,T[r--]);
        }
        return ret;
    }
} eka;

ll N, X, A[sz], S[sz];

void sol(int tc) {
    cin >> N >> X;
    vector<ll> v;
    for(int i=1;i<=N;i++) cin >> A[i], S[i]=S[i-1]+A[i], v.push_back(S[i]);
    v.push_back(0);
    sort(v.begin(),v.end());
    int ans=1e9;
    for(int i=1;i<=N;i++) {
        int ii = eka.qry(0,upper_bound(v.begin(),v.end(),S[i]-X)-v.begin()-1);
        if(S[i]-S[ii] >= X) ans = min(ans, i-ii);
        int j=lower_bound(v.begin(),v.end(),S[i])-v.begin();
        eka.upd(j,i);
    }
    for(int i=0;i<=N;i++) eka.upd(i,0);
    if(ans >= 1e9) cout << "-1\n";
    else cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}