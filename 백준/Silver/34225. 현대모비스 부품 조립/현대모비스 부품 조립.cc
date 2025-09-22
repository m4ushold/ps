#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
void sol(int tc) {
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    ll sum=0, s=0, idx=0, mx=0;
    for(int i=0;i<n;i++) cin >> v[i].first, v[i].second=i, s+=v[i].first;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        int x = v[i].first;
        if(mx < x+s-sum) mx=x+s-sum, idx=i;
        sum+=x;
    }
    vector<int> ans;
    for(int i=idx;i<n;i++) ans.push_back(v[i].second);
    cout << ans.size() << '\n';
    for(int i:ans) cout << i+1 << ' ';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}