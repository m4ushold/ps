#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr int SZ = 10'000'000;
bool PrimeCheck[SZ+1]; vector<int> Primes;
void Sieve(){
    memset(PrimeCheck, true, sizeof PrimeCheck);
    PrimeCheck[0] = PrimeCheck[1] = false;
    for(int i=2; i<=SZ; i++){
        if(PrimeCheck[i]) Primes.push_back(i);
        for(auto j : Primes){
            if(i*j > SZ) break;
            PrimeCheck[i*j] = false;
            if(i % j == 0) break;
        }
    }
}

ull MulMod(ull a, ull b, ull c){ return (__uint128_t)a * b % c; }
ull PowMod(ull a, ull b, ull c){
    ull res = 1; a %= c;
    for(; b; b>>=1, a=MulMod(a,a,c)) if(b & 1) res = MulMod(res,a,c);
    return res;
}
ll Pow(ll a, ll b) {
    ll res=1;
    while(b) {
        if(b&1) res*=a;
        a*=a, b/=2;
    }
    return res;
}

bool MillerRabin(ull n, ull a){
    if(a % n == 0) return true;
    int cnt = __builtin_ctzll(n - 1);
    ull p = PowMod(a, n >> cnt, n);
    if(p == 1 || p == n - 1) return true;
    while(cnt--) if((p=MulMod(p,p,n)) == n - 1) return true;
    return false;
}

bool IsPrime(ll n){
    if(n <= SZ) return PrimeCheck[n];
    if(n <= 2) return n == 2;
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 11 == 0) return false;
    // 32bit integer: {2, 7, 61}
    for(int p : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) if(!MillerRabin(n, p))
    return false;
    return true;
}

ll Rho(ll n){
    while(true){
        ll x = rand() % (n - 2) + 2, y = x, c = rand() % (n - 1) + 1;
        while(true){
            x = (MulMod(x, x, n) + c) % n;
            y = (MulMod(y, y, n) + c) % n;
            y = (MulMod(y, y, n) + c) % n;
            ll d = __gcd(abs(x - y), n);
            if(d == 1) continue;
            if(IsPrime(d)) return d;
            else{ n = d; break; }
        }
    }
}
vector<pair<ll,ll>> Factorize(ll n){
    vector<pair<ll,ll>> v;
    int two = __builtin_ctzll(n);
    if(two > 0) v.emplace_back(2, two), n >>= two;
    if(n == 1) return v;
    while(!IsPrime(n)){
        ll d = Rho(n), cnt = 0;
        while(n % d == 0) cnt++, n /= d;
        v.emplace_back(d, cnt);
        if(n == 1) break;
    }
    if(n != 1) v.emplace_back(n, 1);
    return v;
}

ll N, L;
vector<pair<ll,ll>> v;

bool f(string &s) {
    if(s.size() != L/2) return 0;
    for(int i=1;i<s.size();i++) if(s[i-1]=='0' && s[i]=='0') return 0;
    return 1;
}

bool chk(int idx=0, ll x=1) {
    if (idx == v.size()) {
        if(x%10 == 0 && N/x%10 == 0) return 0;
        auto s = to_string(x), t = to_string(N/x);
        vector<int> cnt(10);
        for(char c:to_string(N)) cnt[c-'0']++;
        for(char c:s) cnt[c-'0']--;
        for(char c:t) cnt[c-'0']--;
        for(int i:cnt) if(i) return 0;
        return f(s) && f(t);
    }
    
    auto [p,a] = v[idx];
    ll mul = 1, res = 0;
    for(int i = 0; i <= a; i++) {
        res |= chk(idx + 1, x * mul);
        if(res) break;
        mul *= p;
    }
    return res;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Sieve();
    while(cin >> N && N) {
        L = to_string(N).size();
        v = Factorize(N);
        int a = (~L&1) && chk();
        cout << N << ": " << (a ? "yes" : "no") << '\n';
    }
    return 0;
}