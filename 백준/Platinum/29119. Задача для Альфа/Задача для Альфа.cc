#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b) {
    return a+b > b+a;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    sort(v.begin(),v.end(),cmp);
    for(auto i:v) cout << i << ' ';
    return 0;
}