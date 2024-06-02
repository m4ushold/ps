#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string a,b;
    map<string,vector<string>> m;
    for(int i=0;i<n;i++) cin >> a >> b, m[a].push_back(b);
    for(auto [c,v]:m) {
        sort(v.begin(),v.end(),greater<>());
        for(auto i:v) cout << c << ' ' << i << '\n';
    }
    return 0;
}