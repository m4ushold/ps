#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    ll a,b,n; cin >> a >> b >> n;
    vector<ll> v;
    ll s = sqrt(n), tmpn=n;
    for(int i=2;i<=s;i++) {
        if(tmpn%i==0) {
            while(tmpn%i==0) tmpn/=i;
            v.push_back(i);
        }
    }
    if(tmpn>1) v.push_back(tmpn);

    int k=v.size();
    ll ans=0;
    for(int i=1;i<1<<k;i++) {
        ll tmp=1,tt=-1;
        for(int j=0;j<k;j++) if(i&(1<<j)) tmp*=v[j], tt*=-1;
        ans += (b/tmp - (a-1)/tmp) * tt;
    }
    cout << "Case #" << tc << ": " << b-a-ans+1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}