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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll a,b,i,n; cin >> a >> b >> i >> n;
        ll r=(__int128_t)a%b*pow(10,i-1,b)%b;
        for(int j=0;j<n;j++,i++) cout << (ll)((__int128_t)a%b*pow(10,i-1,b)%b*10/b);
        cout << '\n';
    }
    return 0;
}