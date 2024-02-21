#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    sort(v.begin(), v.end());
    cout << v[m-1];
    return 0;
}