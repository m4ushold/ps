#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll pw(ll a, ll n, ll m) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%m;
        a=a*a%m, n>>=1;
    }
    return res;
}

bool miller(ll a,ll n) {
    if(a % n == 0) return 0;
    ll d=n-1;
    while(1) {
        ll tmp = pw(a, d, n);
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

void sol() {
    vector<int> v(5);
    ll sum=0;
    for(int &i:v) {
        cin >> i;
        for(int j=i;;j++) if(is_prime(j)) {sum+=j; break;}
    }
    cout << sum << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}