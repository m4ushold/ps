#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll l=n,r=1e12;
    while(l<r) {
        ll m=l+r>>1;
        if(m-m/3-m/5+m/15 >= n) r=m;
        else l=m+1;
    }
    cout << r;
    return 0;
}