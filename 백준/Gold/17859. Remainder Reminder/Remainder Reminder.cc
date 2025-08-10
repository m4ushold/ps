#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod(ll a, ll b) { return ((a%b) + b) % b; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

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

void sol(int tc) {
    ll a,b,c,d,e,f,g; cin >> a >> b >> c >> d >> e >> f >> g;
    vector<ll> v;
    for(ll x=1;x<=a/2;x++) v.push_back(x*(a-2*x)*(b-2*x));
    sort(v.begin(),v.end(),greater<>());
    v.erase(unique(v.begin(),v.end()),v.end());

    auto [x,m] = crt({c,d,e},{v[0],v[1],v[2]});
    ll ans=(f/m)*m+x;
    while(ans>g) ans-=m;
    while(ans<f) ans+=m;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}