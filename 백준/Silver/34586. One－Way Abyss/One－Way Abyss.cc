#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n,m; cin >> n >> m;
    vector<ll> v(n+1);
    for(int i=0;i<m;i++) {
        ll a,b,c; cin >> a >> b >> c;
        ll t1 = v[a]+c;
        ll t2 = v[b]+c;
        v[b]=t1, v[a]=t2;
    }
    cout << *max_element(v.begin(),v.end()) << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}