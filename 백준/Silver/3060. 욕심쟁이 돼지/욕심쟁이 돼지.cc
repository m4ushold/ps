#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> v(6);
        for(ll &i:v) cin >> i;
        ll a=accumulate(v.begin(),v.end(),0);
        int cnt=1;
        while(a<=n) a*=4, cnt++;
        cout << cnt << '\n';
    }
    return 0;
}