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
    for(int a : {2,3,61}) if(miller(a,n)) return 0;
    return 1;
}

int N;

void f(ll n, int len) {
    if(len == N) {cout << n << '\n'; return;}
    for(int i=1;i<10;i++) if(is_prime(n*10+i)) f(n*10+i, len+1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    f(0,0);
    return 0;
}