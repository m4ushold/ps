#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    map<char,int> m({{'H',0},{'I',0},{'A',0},{'R',0},{'C',0}});
    for(char c:s) if(c=='H' || c=='I' || c=='A' || c=='R' || c=='C') m[c]++;
    int mn=1e9;
    for(auto [i,j]:m) mn=min(mn,j);
    cout << mn;
    return 0;
}