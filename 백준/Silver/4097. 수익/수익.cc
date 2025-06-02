#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int n) {
    vector<ll> v(n);
    ll sum=0, mn=0, dap=LLONG_MIN;
    for(ll &i:v) cin >> i, sum+=i, i=sum;
    for(ll i:v) dap=max(dap, i-mn), mn=min(mn,i);
    cout << dap << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while(cin >> n && n) sol(n);
    return 0;
}