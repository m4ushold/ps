#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;

void solve(){
    int n, m; cin >> m >> n;
    vector<P> v;
    vector<array<int,3>> a;
    for(int i=1;i<=m;i++) {
        int u,v; cin >> u >> v;
        if(u>v) swap(u,v);
        a.push_back({u,v,i});
    }
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    sort(a.begin(),a.end());

    int idx=0;
    vector<int> ans(n);
    for(auto [x,i]:v) {
        while(idx < m && a[idx][0]<x && a[idx][1]<x) idx++;
        if(idx>=m || a[idx][0]!=x && a[idx][1]!=x) {
            cout << "impossible\n";
            return;
        }
        ans[i-1]=a[idx][2];
        idx++;
    }
    for(int i:ans) cout << i << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}