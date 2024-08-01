#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int id) {
    ll n, m; cin >> n >> m;
    set<ll> s;
    ll g=gcd(n-1, m-1);
    for(ll i=1;i*i<=g;i++) if(g%i==0) s.insert(i), s.insert(g/i);
    
    g=gcd(n-2, m);
    for(ll i=1;i*i<=g;i++) if(g%i==0) s.insert(i), s.insert(g/i);
    
    g=gcd(n, m-2);
    for(ll i=1;i*i<=g;i++) if(g%i==0) s.insert(i), s.insert(g/i);
    
    g=gcd(gcd(n-1, m-2), m);
    for(ll i=1;i*i<=g;i++) if(g%i==0) s.insert(i), s.insert(g/i);
    
    g=gcd(gcd(m-1, n-2), n);
    for(ll i=1;i*i<=g;i++) if(g%i==0) s.insert(i), s.insert(g/i);
    
    cout << s.size() << ' ';
    for(ll i:s) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}