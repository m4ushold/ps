#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<pair<int,int>> v;
    for(int i=1,x;i<=m;i++) {
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(),v.end());
    while(v.size() && v.back().first>2*n) v.pop_back();

    ll a=0;
    vector<int> ans;
    while(v.size()) {
        auto [x,i]=v.back(); v.pop_back();
        if(a+x <= 2*n) a+=x, ans.push_back(i);

        if(a>=n) break;
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(int i:ans) cout << i << '\n';
    return 0;
}