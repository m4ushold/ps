#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i, i=i&1?i/2+1:i/2-1;
    int x=reduce(v.begin(),v.end(),0LL,bit_xor<ll>());
    cout << (x ? "koosaga" : "cubelover");
    return 0;
}