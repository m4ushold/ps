#include <bits/stdc++.h>
using namespace std;

int N, M, IN[10101], D[10101], E[10101];
vector<pair<int,int>> G[10101], R[10101];

vector<int> f()
{
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=N;i++) if (!IN[i]) q.push(i);
    while(!q.empty()) {
        int v=q.front(); q.pop();
        res.push_back(v);
        for(auto [i,w]:G[v]) {
            if (!--IN[i]) q.push(i);
        }
    }
    return res;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,s,e,w;i<M;i++) cin >> s >> e >> w, IN[e]++, G[s].push_back({e,w}), R[e].push_back({s,w});
    int s,e; cin >> s >> e;
    vector<int> v=f();
    for(int i:v) for(auto [j,w]:G[i]) D[j]=max(D[j], D[i]+w);
    reverse(v.begin(),v.end());
    int cnt=0;
    queue<int> q; q.push(e);
    while(q.size()) {
        int i=q.front(); q.pop();
        for(auto [j,w]:R[i]) if(D[i]==D[j]+w) {
            cnt++;
            if(!E[j]) q.push(j), E[j]=1;
        }
    }
    cout << D[e] << '\n' << cnt;
    return 0;
}