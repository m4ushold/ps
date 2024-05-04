#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; int n;
    vector<pair<int,string>> v;
    while(cin >> s >> n) v.push_back({n,s});
    sort(v.begin(),v.end());
    cout << v[0].second;
    return 0;
}