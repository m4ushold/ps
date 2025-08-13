#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int SZ = 1010;
vector<int> prime;
ll sp[SZ], phi[SZ], a, d[SZ][SZ];

ll pw(__int128_t a, ll n, ll mod) {
    __int128_t res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n/=2;
    }
    return res;
}

void Sieve(ll n=SZ-1) {
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

ll pw_bound(ll b, ll n, ll mod) {
    __int128_t res = 1;
    for(ll i=0;i<n;i++) {
        res *= b;
        if (res >= mod) return mod;
    }
    return (ll)res;
}

bool tower_ge_mod(ll b, ll mod) {
    if(mod <= 1) return 1;
    ll x=a;
    for(int i=0;i<b;i++) {
        if(x>=mod) return 1;
        if(x<=1) return 0;
        x=pw_bound(x, x, mod);
    }
    return x>=mod;
}

ll pwTower(ll b, ll mod) {
    if(mod == 1) return 0;
    if(b==0) return a%mod;
    ll &res = d[b][mod];
    if(res!=-1) return res;

    ll aa = pwTower(b-1,mod), e = pwTower(b-1,phi[mod]);
    e += tower_ge_mod(b-1,phi[mod]) ? phi[mod] : 0;
    return res = pw(aa,e,mod);
}

void sol(int tc) {
    ll b,c; cin >> a >> b >> c;
    for(int i=0;i<=b;i++) for(int j=0;j<=c;j++) d[i][j]=-1;
    cout << "Case #" << tc << ": ";
    if(a==1) cout << a%c << '\n';
    else cout << pwTower(b,c) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Sieve();
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}