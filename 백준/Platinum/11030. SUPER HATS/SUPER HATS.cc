#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll pw(__int128_t a, ll n, ll mod) {
    __int128_t res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n/=2;
    }
    return res;
}

ll phi(ll n) {
	ll res=n;
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0) {
			res-=res/i;
			while(n%i==0) n/=i;
		}
	}
	if(n!=1) res-=res/n;
	return res;
}

bool PowOverflow(ll a, ll b, ll c){
    __int128_t res = 1;
    bool flag = false;
    for(; b; b >>= 1, a = a * a){
        if(a >= c) flag = true, a %= c;
        if(b & 1){
        res *= a; if(flag || res >= c) return true;
        }
    }
    return false;
}
ll Recursion(int idx, ll mod, const vector<ll> &vec){
    if(mod == 1) return 1;
    if(idx + 1 == vec.size()) return vec[idx];
    ll nxt = Recursion(idx+1, phi(mod), vec);
    if(PowOverflow(vec[idx], nxt, mod)) return pw(vec[idx], nxt, mod) + mod;
    else return pw(vec[idx], nxt, mod);
}
ll PowerTower(const vector<ll> &vec, ll mod){ // vec[0]^(vec[1]^(vec[2]^(...))), suppose vec[i] >= 2
    if(vec.size() == 1) return vec[0] % mod;
    else return pw(vec[0], Recursion(1, phi(mod), vec), mod);
}

ll f(ll a, ll b) {
    if(a==2 && b>4) return -1;
    else if(3<=a && a<9 && b>2) return -1;
    else if(9<=a && b>1) return -1;
    else if(1e8<=a) return -1;

    ll t = a;
    for(int i=1;i<b;i++) {
        t = pw(a,t,LONG_LONG_MAX);
    }
    return t;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b; cin >> a >> b;

    ll ans=f(a,b);
    if(a==1) return cout << 1, 0;
    if(ans>-1) return cout << ans, 0;
    
    vector<ll> v(min(b,100LL), a);
    ans=PowerTower(v, 1e8);
    cout << setw(8) << setfill('0') << ans;
    return 0;
}