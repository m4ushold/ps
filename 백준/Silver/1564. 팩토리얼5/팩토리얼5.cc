#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;

const ll MOD=1e12;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll res=1;
    for(int i=2;i<=n;i++) {
        res=res*i;
        while(res%10 == 0) res/=10;
        res%=MOD;
    }
    cout << setw(5) << setfill('0') << res%100'000;
    return 0;
}