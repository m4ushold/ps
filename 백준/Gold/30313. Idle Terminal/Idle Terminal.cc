#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n,m; cin >> n >> m;
    priority_queue<int,vector<int>,greater<>> pq;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    for(int i=0;i<min(n,m);i++) pq.push(v[i]);

    int time=0, mx=0;
    for(int i=min(n,m);i<n;i++) {
        // cout << pq.top() << ' ' << time << endl;
        mx=max(mx,pq.top()-time);
        time = pq.top();
        pq.pop();
        pq.push(time+v[i]);
    }
    while(pq.size()) {
        mx=max(mx,pq.top()-time);
        // cout << pq.top() << ' ' << time << endl;
        time = pq.top();
        pq.pop();
    }
    cout << mx << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}