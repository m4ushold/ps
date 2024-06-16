#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll pow(ll b, ll e, ll mod) {
    ll ret = 1;
    while(e){
        if(e&1) ret=((__int128_t)ret*b)%mod;
        b=((__int128_t)b*b)%mod; 
        e >>= 1;
    }
    return ret;
}

bool miller(ll a,ll n)
{
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
    for(int a : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if(miller(a,n)) return 0;
    }
    return 1;
}

void PollardRho(ll n, vector<ll>& v)
{
    if (n==1) return;
    if (!(n&1)) {
        v.push_back(2);
        PollardRho(n/2,v);
        return;
    }
    if (is_prime(n)) {
        v.push_back(n);
        return;
    }
 
    ll x = (rand()%(n-2))+2, y=x, c=(rand()%(20))+1, g = 1; 
    auto f = [&](ll x){ return (((__int128_t)x*x)%n+c)%n; };
 
    while (g==1) {
        x=f(x);
        y=f(f(y));
        g=gcd(abs(x-y), n);
    }
    PollardRho(g,v);
    PollardRho(n/g,v);
}

vector<ll> factorize(ll n) {
    vector<ll> v, ret;
    PollardRho(n, v);
    sort(v.begin(),v.end());
    for(ll i:v) if (ret.empty() || ret.back()!=i) ret.push_back(i);
    return ret;
}

ll phi(ll n) {
    if(n==1 || !n) return 0;
    ll phi=n;
    for(ll i : factorize(n)) phi=phi/i*(i-1);
    return phi;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    srand(time(NULL));
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        cout << phi(n) + (n&1?0:phi(n/2)) << "\n";
    }
    return 0;
}