#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll A[1010101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i, A[i]=1;
    ll dap=0;
    for(ll i:v) {
        ll t=i+1;
        while(t*t - i*i <= 1'000'000) {
            if(A[t*t - i*i]) dap++;
            t++;
        }
    }
    cout << dap;
    return 0;
}