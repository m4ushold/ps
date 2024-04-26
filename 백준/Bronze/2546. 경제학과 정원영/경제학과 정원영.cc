#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        vector<ll> a(n), b(m);
        for(ll &i:a) cin >> i;
        for(ll &i:b) cin >> i;
        ll as=accumulate(a.begin(),a.end(),0LL);
        ll bs=accumulate(b.begin(),b.end(),0LL);

        int cnt=0;
        for(ll i:a) if(as > i*n && bs < i*m) cnt++;
        cout << cnt << '\n';
    }
    return 0;
}