#include <bits/stdc++.h>
using namespace std;

int N, IN[55], A[55];
vector<int> G[55];

vector<int> tSort() {
    priority_queue<int> q;
    vector<int> res;
    for(int i=1;i<=N;i++) if (!IN[i]) q.push(i);
    while(!q.empty()) {
        int v=q.top(); q.pop();
        res.push_back(v);
        for(int i : G[v]) {
            IN[i]--;
            if (!IN[i]) q.push(i);
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        char c; cin >> c;
        if(c=='1') G[j].push_back(i), IN[i]++;
    }
    
    vector<int> ans(N), v = tSort();
    for(int i=1;i<=N;i++) if(IN[i]) return cout << -1, 0;
    reverse(v.begin(),v.end());

    for(int i=0;i<N;i++) ans[v[i]-1] = i+1;
    for(int i:ans) cout << i << ' ';
    return 0;
}