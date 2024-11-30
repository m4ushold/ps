#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int MOD=1e9+7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    ll res=1;
    for(int i=n-1;i>0;i-=2) res=res*i%MOD;
    cout << res;
    return 0;
}