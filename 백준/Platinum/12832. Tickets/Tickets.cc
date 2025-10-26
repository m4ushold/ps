#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<int,int>;

void sol(int tc) {
    int n,m; cin >> n >> m;
    vector<array<int,3>> v;
    for(int i=1;i<=m;i++) {
        int l,r; cin >> l >> r;
        v.push_back({l,r,i});
    }
    sort(all(v));
    
    priority_queue<pll,vector<pll>,greater<>> pq;
    int idx=0, cnt=0;
    for(int i=1;i<=n;i++) {
        while(idx<m && v[idx][0]==i) pq.push({v[idx][1], v[idx][2]}), idx++;
        while(pq.size() && pq.top().first < i) pq.pop();
        if(pq.size()) cnt++, pq.pop();
    }
    cout << cnt << endl;
    while(pq.size()) pq.pop();
    idx=0;
    for(int i=1;i<=n;i++) {
        while(idx<m && v[idx][0]==i) pq.push({v[idx][1], v[idx][2]}), idx++;
        while(pq.size() && pq.top().first < i) pq.pop();
        if(pq.size()) cout << i << ' ' << pq.top().second << endl, pq.pop();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}