#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll S[101010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,k; cin >> n >> m >> k;
    ll s=0;
    for(int i=1;i<=m;i++) {
        int t,r; cin >> t >> r;
        s+=r;
        if(s > k) return cout << i << ' ' << 1, 0;
    }
    cout << -1;
    return 0;
}