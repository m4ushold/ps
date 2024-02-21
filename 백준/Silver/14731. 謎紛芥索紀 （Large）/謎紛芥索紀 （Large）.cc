#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;

ll pow(ll b, ll e) {
    if(e<0) return 0;
    ll ret = 1;
    while(e){
        if(e&1) ret=((__int128_t)ret*b)%MOD;
        b=((__int128_t)b*b)%MOD; 
        e >>= 1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll res=0;
    for(ll i=0,a,b;i<n;i++) {
        cin >> a >> b;
        res = (res + (a*b%MOD*pow(2LL,b-1))%MOD)%MOD;
    }
    cout << res;
    return 0;
}