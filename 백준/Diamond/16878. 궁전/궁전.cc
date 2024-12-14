#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
ll D[10'000'001]={1,1,0,0,2};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=5;i<=10'000'001;i++) {
        D[i]=(i+1)*D[i-1]%MOD - (i-2)*D[i-2]%MOD - (i-5)*D[i-3]%MOD + ((i-3))*D[i-4]%MOD;
        D[i] = (D[i]%MOD + MOD)%MOD;
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << D[n] << '\n';
    }
    return 0;
}