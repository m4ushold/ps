#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n,t; cin >> n >> t;
    vector<pll> v(n);
    for(auto &[a,b]:v) cin >> b >> a;
    sort(all(v));
    priority_queue<int,vector<int>,greater<>> pq;
    for(auto [tt,c]:v) {
        if(pq.size() <= tt) pq.push(c);
        else {
            if(pq.top() < c) {
                pq.pop();
                pq.push(c);
            }
        }
    }
    ll a=0;
    while(pq.size()) a+=pq.top(), pq.pop();
    cout << a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}