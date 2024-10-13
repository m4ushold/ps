#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ = 1010101;
vector<int> prime;
int sp[SZ], phi[SZ];

ll pw(__int128_t a, ll n, ll mod) {
    __int128_t res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n/=2;
    }
    return res;
}

void Sieve(ll n) {
    phi[1] = 1;
    for(int i=2; i<=n; i++){
        if(!sp[i]){
            prime.push_back(i);
            phi[i] = i-1;
        }
        for(auto j : prime){
            if(i*j >= SZ) break;
            sp[i*j] = j;
            if(i % j == 0) {
                phi[i*j] = phi[i]*j;
                break;
            }
            phi[i*j] = phi[i] * phi[j];
        }
    }
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
    ll nxt = Recursion(idx+1, phi[mod], vec);
    if(PowOverflow(vec[idx], nxt, mod)) return pw(vec[idx], nxt, mod) + mod;
    else return pw(vec[idx], nxt, mod);
}
ll PowerTower(const vector<ll> &vec, ll mod){ // vec[0]^(vec[1]^(vec[2]^(...)))
    if(vec.size() == 1) return vec[0] % mod;
    else return pw(vec[0], Recursion(1, phi[mod], vec), mod);
}

void sol(ll mod) {
    int n; cin >> n;
    vector<ll> v;
    for(int i=0,f=1,x;i<n;i++) {
        cin >> x;
        if(x==1) f=0;
        if(f) v.push_back(x);
    }
    if(v.size()) cout << PowerTower(v, mod) << '\n';
    else cout << "1\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, m; cin >> t >> m;
    Sieve(m);
    while(t--) sol(m);
    return 0;
}