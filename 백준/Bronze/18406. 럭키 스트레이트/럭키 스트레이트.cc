#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    ll l=0, r=0;
    for(int i=0;i<s.size();i++) i < s.size()/2 ? l+=s[i] : r+=s[i];
    cout << (l==r ? "LUCKY" : "READY");
    return 0;
}