#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<pair<int,int>> v(m);
    for(int i=0;i<n;i++) {
        for(int j=0,x;j<m;j++) cin >> x, v[j].first+=x, v[j].second=j+1;
    }
    sort(v.begin(),v.end(),[](pair<int,int> a, pair<int,int> b){
        if(a.first!=b.first) return a.first > b.first;
        return a.second < b.second;
    });
    for(auto [i,j]:v) cout << j << ' ';
    return 0;
}