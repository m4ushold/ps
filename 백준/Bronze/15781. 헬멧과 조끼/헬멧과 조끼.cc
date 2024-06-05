#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for(ll &i:a) cin >> i;
    for(ll &i:b) cin >> i;
    cout << *max_element(a.begin(),a.end())+*max_element(b.begin(),b.end());
    return 0;
}