#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int f=1;
    for(int i=0;i<s.size()/2;i++) f&=s[i]==s[s.size()-i-1];
    cout << (f ? "true" : "false");
    return 0;
}