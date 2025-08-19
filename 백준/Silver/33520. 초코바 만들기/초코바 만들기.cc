#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n; cin >> n;
    ll mn=0, mx=0;
    for(int i=0;i<n;i++) {
        ll a,b; cin >> a >> b;
        if(a>b) swap(a,b);
        mn=max(mn,a), mx=max(mx,b);
    }
    cout << mn*mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}