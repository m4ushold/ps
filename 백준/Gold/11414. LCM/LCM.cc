#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a,b);
}

void sol(int tc) {
    ll a,b; cin >> a >> b;
    vector<ll> v;
    if(a > b) swap(a,b);
    ll x = abs(a-b);
    if(x==0) {
        cout << 1;
        return;
    }
    for(ll i=1;i*i<=x;i++) {
        if(x%i==0) {
            v.push_back(i);
            v.push_back(x/i);
        }
    }
    ll mn=LLONG_MAX, ans=0;
    for(ll i:v) {
        ll n = (i-a%i);
        ll aa=a+n, bb=b+n, l = lcm(aa,bb);
        if(mn > l) mn=l, ans=n;
        else if(mn == l) ans=min(ans, n);
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}