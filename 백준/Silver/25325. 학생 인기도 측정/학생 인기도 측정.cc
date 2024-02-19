#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b) {
    return a.second==b.second?a.first<b.first:a.second>b.second;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    map<string,int> m;
    string s; 
    for(int i=0;i<n;i++) cin >> s, m[s]=0;
    while(cin >> s) m[s]++;
    vector<pair<string,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    for(auto [a,b]:v) cout << a <<' ' << b << '\n';
    return 0;
}