#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b; cin >> a >> b;
    ll res=0;
    for(char i:a) for(char j:b) res+=(i-'0')*(j-'0');
    cout << res;
    return 0;
}