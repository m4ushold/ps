#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t,a; cin >> t;
    string s;
    while(t--) cin >> a >> s, cout << s.substr(0,a-1) << s.substr(a) << '\n';
    return 0;
}