#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> v;
    int in=0, out=0, fa=0;
    for(ll i=1,x,y;i<=n;i++) {
        cin >> x >> y;
        if(y>=x && y>=-x) v.push_back(x*x+y*y);
        else fa++;
    }
    sort(v.begin(),v.end());

    int q; cin >> q;
    while(q--) {
        ll r; cin >> r;
        r*=r;
        out= v.end()-upper_bound(v.begin(),v.end(),r);
        in=n-out-fa;
        cout << fa << ' ' << in << ' ' << out << '\n';
    }
    return 0;
}