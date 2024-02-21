#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<ll,string>> v(n);
    for(auto &[i,j]:v) cin >> j >> i, i=1e9-i;
    sort(v.begin(),v.end());
    cout << v[0].second;
    return 0;
}