#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;

    cout << (s.substr(0,n/2) == s.substr(n/2) ? "Yes" : "No");
    return 0;
}