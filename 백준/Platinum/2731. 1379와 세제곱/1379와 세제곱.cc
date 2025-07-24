#include <bits/stdc++.h>
using namespace std;
using ll=__int128_t;

long long n;

bool chk(ll x, ll m) {
    return x*x%m*x%m == n%m;
}

ll f(ll x=0, ll b=1) {
    if(x%b*x%b*x%b == n) return x;

    ll res=-1;
    for(int i=0;i<=9;i++) {
        if(chk(x+b*i, b*10)) {
            ll tmp = f(x+b*i,b*10);
            if(tmp != -1) res = tmp;
        }
    }
    return res;
}

void sol() {
    cin >> n;
    cout << (long long)f() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}