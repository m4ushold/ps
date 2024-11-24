#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,k; cin >> n >> k;
    vector<ll> v;
    v.push_back(0);
    for(int i=0;i<n;i++) {
        ll a,b; cin >> a >> b;
        v.push_back(max(b-a,0LL));
    }
    sort(v.begin(),v.end());
    cout << v[k];
    return 0;
}