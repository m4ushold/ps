#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    map<char,int> m;
    while(n--) {
        string s; cin >> s;
        m[s[0]]++;
    }
    int cnt=0;
    for(auto [i,j]:m) if(j>=5) cout << i, ++cnt;
    if(!cnt) cout << "PREDAJA";
    return 0;
}