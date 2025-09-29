#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;

bool sol() {
    int n; cin >> n;
    vector<int> v(n), smx(n);
    for(int &i:v) cin >> i;
    smx.back() = v.back();
    for(int i=n-2;i>=0;i--) smx[i]=max(smx[i+1], v[i]);
    set<int> s;
    for(int i=0;i<n;i++) {
        s.insert(v[i]);
        int x = *s.upper_bound(v[i]);
        if(x<smx[i] && v[i]<x) return 1;
    }
    return 0;
}

void solve(){
    int n; cin >> n;
    vector<int> ans;
    for(int i=1;i<=n;i++) {
        if(sol()) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(int i:ans) cout << i << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}