#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first==b.first?a.second<b.second:a.first>b.first;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &[a,b]:v) cin >> a >> b;
    sort(v.begin(),v.end(),cmp);
    int c=5;
    while(c<n && v[4].first==v[c].first) ++c;
    cout << c-5;
    
    return 0;
}