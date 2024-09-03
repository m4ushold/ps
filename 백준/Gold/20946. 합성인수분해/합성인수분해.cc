#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow(ll b, ll e, ll mod) {
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
    // int: 2,3,61
    // ll : 2,3,5,7,11,13,17,19,23,29,31,37
    if (n==0||n==1) return 0;
    for(int a : {2,3,5,7,11,13,17,19,23,29,31,37}) if(miller(a,n)) return 0;
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
    vector<ll> v;
    PollardRho(n, v);
    sort(v.begin(),v.end());
    return v;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    auto v=factorize(n);
    if(v.size()<2) cout << -1;
    else {
        if(v.size()&1) {
            ll a= v.back();
            v.pop_back();
            v[v.size()-1]*=a;
        }
        for(int i=0;i<v.size();i+=2) cout << v[i]*v[i+1] << ' ';
    }
    return 0;
}