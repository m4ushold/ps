#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end(),greater<>());

    ll ans=v[0];
    for(int i=1;i<(int)sqrt(n);i++) {
        if(v[i]>0) ans+=v[i];
        else break;
    }
    cout << ans;
    return 0;
}