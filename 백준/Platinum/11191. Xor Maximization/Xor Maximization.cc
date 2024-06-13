#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll Gauss(vector<ll> &v) {
    int n=v.size(), rank=0;
    for(ll i=1LL<<59;i&&rank<n;i>>=1) {
        if(~v[rank]&i) {
            int j=-1;
            for(int k=rank+1;k<n;k++) if(v[k]&i) {j=k; break;}
            if(j==-1) continue;
            v[rank]^=v[j];
        }
        for(int j=0;j<n;j++) {
            if(j==rank) continue;
            if(v[j]&i) v[j]^=v[rank];
        }
        rank++;
    }
    return reduce(v.begin(),v.end(),0LL,[](ll a, ll b){return a^b;});
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    cout << Gauss(v);
    return 0;
}