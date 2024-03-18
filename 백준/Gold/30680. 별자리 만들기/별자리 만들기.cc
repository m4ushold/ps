#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, H;
vector<int> G[505050];
priority_queue<int,vector<int>,greater<>> pq;

void dfs(int v=1, int p=-1, int h=1) {
    for(int i:G[v]) if(p!=i) dfs(i,v, h+1);
    if(v!=1 && G[v].size()==1) pq.push(H+h);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    pq.push(0);
    cin >> N;
    for(int i=0,n;i<N;i++) {
        cin >> n;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1,u,v;i<n;i++) cin >> u >> v, G[v].push_back(u), G[u].push_back(v);
        H=pq.top(); pq.pop();
        dfs();
    }
    int mx=0;
    while(!pq.empty()) {
        mx=max(mx,pq.top()); pq.pop();
    }
    cout << mx;
    return 0;
}