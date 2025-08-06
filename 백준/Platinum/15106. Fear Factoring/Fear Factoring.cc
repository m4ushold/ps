#include <bits/stdc++.h>
using namespace std;
using ll=long long;

__int128_t s(__int128_t n) {
    return n*(n+1)/2;
}

__int128_t f(ll n) {
    __int128_t ans=0;
    for(ll i=1 ; i<=n ;) {
		ll j=n/(n/i);
        ans += (n/i)*(s(j)-s(i-1));
        i=j+1;
	}
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll a,b; cin >> a >> b;
    cout << (ll)(f(b)-f(a-1));
    return 0;
}