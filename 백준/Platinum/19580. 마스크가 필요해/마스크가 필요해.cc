#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n,m; cin >> n >> m;
    vector<pll> a,b;
    for(int i=0;i<n;i++) {
        ll x,y; cin >> x >> y;
        a.push_back({x,y});
    }
    for(int i=0;i<m;i++) {
        ll x,y; cin >> x >> y;
        b.push_back({x,y});
    }
    sort(all(a)), sort(all(b));

    int idx=0, cnt=0;
    priority_queue<ll,vector<ll>,greater<>> pq;
    for(auto [p,x]:b) {
        while(idx < n && a[idx].first <= p) pq.push(a[idx].second), idx++;
        while(pq.size() && pq.top() < p) pq.pop();
        while(pq.size() && x--) {
            cnt++;
            pq.pop();
        }
    }
    cout << cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}