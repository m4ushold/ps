#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<int,int>> v(11);
    for(auto &[i,j]:v) cin >> i >> j;
    sort(v.begin(),v.end());
    ll t=0, p=0;
    for(auto [i,j]:v) t+=i, p+=t+20*j;
    cout << p;
    return 0;
}