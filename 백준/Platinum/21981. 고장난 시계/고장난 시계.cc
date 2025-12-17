#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll mod(ll a, ll b) { return ((a%b) + b) % b; }

tuple<ll,ll,ll> ext_gcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};
    auto [g,x,y] = ext_gcd(b, a % b);
    return {g, y, x - a/b * y};
}
ll inv(ll a, ll m){
    auto [g,x,y] = ext_gcd(a, m);
    return g == 1 ? mod(x, m) : -1;
}
pair<ll,ll> crt(ll a1, ll m1, ll a2, ll m2){
    ll g = gcd(m1, m2), m = lcm(m1, m2);
    if((a2 - a1) % g) return {-1, -1};
    ll mul = mod((a2-a1)/g, m2);
    ll x = mod(get<1>(ext_gcd(m1, m2)), m2) * mul % m2;
    return { (a1 + x * m1) % m, m };
}
pair<ll,ll> crt(const vector<ll> &a, const vector<ll> &m){
    ll ra = a[0], rm = m[0];
    for(int i=1; i<m.size(); i++){
        auto [aa,mm] = crt(ra, rm, a[i], m[i]);
        if(mm == -1) return {-1, -1}; 
        else tie(ra,rm) = tie(aa,mm);
    }
    return {ra, rm};
}

int fn(string s) {
    return stoi(s.substr(0,2))*60*60 + stoi(s.substr(3,2))*60 + stoi(s.substr(6,2));
}

constexpr int tfh = 86400;

pll fx(ll a, ll b, ll m) { // solve ax \congurent b mod m
    auto [g,x,y] = ext_gcd(a,m);
    if(b%g) return {-1,-1};
    a/=g,b/=g,m/=g;
    tie(g,x,y) = ext_gcd(a,m);
    x = mod(x, m);
    return {b * x % m, m};
}

void sol(int tc) {
    int n; cin >> n;
    if(n==1) {
        cout << tfh << endl;
        return;
    }
    vector<pll> clock;
    vector<ll> a,m;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        clock.emplace_back(fn(s),0);
    }
    for(int i=0;i<n;i++) cin >> clock[i].second;
    for(int i=1;i<n;i++) {
        ll aa = clock[i].second - clock[0].second;
        ll bb = clock[0].first - clock[i].first;

        auto [c,d] = fx(mod(aa,tfh),mod(bb,tfh),tfh);
        if(d==-1) {
            cout << 0 << endl;
            return;
        }
        a.push_back(c), m.push_back(d);
    }

    auto [aa,mm] = crt(a,m);
    if(aa=0) aa=mm;
    ll ans = 0;
    if(aa <= tfh) {
        ans = (tfh - aa) / mm;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}