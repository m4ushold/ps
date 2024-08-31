#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll pow(ll b, ll e, ll mod) {
    ll ret = 1;
    while(e){
        if(e&1) ret=((__int128_t)ret*b)%mod;
        b=((__int128_t)b*b)%mod; 
        e >>= 1;
    }
    return ret;
}

bool miller(ll a,ll n) {
    if(a % n == 0) return 0;
    ll d=n-1;
    while(1) {
        ll tmp = pow(a, d, n);
        if(tmp == n-1) return 0;
        if(d&1){ return tmp != 1; }
        d >>= 1;
    }
}

bool is_prime(ll n) {
    if (n==0||n==1) return 0;
    for(int a : {2,3,5,7,11,13,17,19,23,29,31,37}) if(miller(a,n)) return 0;
    return 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll a,b; cin >> a >> b;
        if((a+b)&1) {
            ll c=a+b-2,f=0;
            if(is_prime(c)) cout << "YES\n";
            else cout << "NO\n";
        } else if(a+b>2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}