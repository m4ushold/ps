#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz=1<<20, mod=998244353;
ll N, F[sz]={1}, I[sz]={1};

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n>>=1;
    }
    return res;
}

ll ncr(ll n, ll r) {
    return F[n]*I[r]%mod*I[n-r]%mod;
}

void sol(int tc) {
    for(int i=1;i<sz;i++) F[i]=F[i-1]*i%mod;
    I[sz-1]=pw(F[sz-1],mod-2);
    for(int i=sz-2;i;i--) I[i]=I[i+1]*(i+1)%mod;
    cin >> N;
    map<int,int> cnt;
    for(int i=0;i<N;i++) {
        int x; cin >> x;
        for(int j=0,y;j<x;j++) cin >> y, cnt[y]++;
    }
    vector<ll> v(N+1);
    for(auto [x,c]:cnt) {
        for(int i=1;i<=c;i++) v[i]+=ncr(c,i), v[i]%=mod;
    }
    for(int i=1;i<=N;i++) cout << v[i] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}