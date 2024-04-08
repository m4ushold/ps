#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=16769023;
ll pow(ll b, ll e, int f) {
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
    cout << pow(2LL,n+1>>1, 1);
    return 0;
}