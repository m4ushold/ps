#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
ll F[101010]={0,1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=2;i<=n+1;i++) F[i]=(F[i-1]+F[i-2])%MOD;
    ll ans=0;
    for(int i=1;i<=n;i++) ans=(ans+F[gcd(i+1,n+1)])%MOD;
    cout << ans;
    return 0;
}