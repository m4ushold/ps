#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    ll n,m; cin >> n >> m;
    vector<ll> v(n);
    for(int i=0,a,b;i<m;i++) cin >> a >> b, v[a-1]++;
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=1;i<n;i++) {
        if(v[i]<v[i-1]+1) ans+=v[i-1]+1-v[i], v[i]=v[i-1]+1;
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}