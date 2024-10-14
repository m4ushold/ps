#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ = 1010101;

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

void sol() {
    ll n, m; cin >> n >> m;
    vector<ll> v(100,n);
    if(n==1) cout << n%m << '\n';
    else cout << PowerTower(v, m) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}