#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a; cin >> a;
        vector<pair<int,int>> v;
        for(int i=1;i<=a;i++) if(a-i > i) v.push_back({i,a-i});
        cout << "Pairs for " << a << ": ";
        if(v.size()>1) for(int i=0;i<v.size()-1;i++) cout << v[i].first << ' ' << v[i].second << ", ";
        if(v.size()) cout << v.back().first << ' ' << v.back().second;
        cout << '\n';
    }
    return 0;
}