#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    int n; cin >> n;
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=0,a;i<n;i++) {
        cin >> a;
        pq.push(a);
    }
    ll res=0;
    while(pq.size()>1) {
        ll a=pq.top(); pq.pop();
        a+=pq.top(), pq.pop();
        res+=a, pq.push(a);
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}