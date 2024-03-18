#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, a=(1<<16)-1; cin >> n;
    string s=bitset<16>(n>>16).to_string();
    reverse(s.begin(),s.end());
    int b=stoi(s,0,2);
    cout << (n&a) + b + !!b;
    return 0;
}