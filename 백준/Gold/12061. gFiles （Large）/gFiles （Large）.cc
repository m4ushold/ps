#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n; cin >> n;
    vector<pair<ll,ll>> v(n);
    ll l=0, r=LLONG_MAX/2;
    for(auto &[i,j]:v) {
        cin >> i >> j;
        if(i==100) {l=r=j;break;}
        if(!i) continue;
        l = max(l,j*100/(i+1)+1), r = min(r,j*100/i);
    }
    cout << "Case #" << tc << ": " << (l==r ? l : -1) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}