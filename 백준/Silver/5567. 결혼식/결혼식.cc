#include <bits/stdc++.h>
using namespace std;

vector<int> G[505];
int N, M, A[505];

void bfs(int s=1) {
    queue<int> q;
    q.push(s), A[s]=1;
    while(q.size()) {
        int v = q.front(); q.pop();
        for(auto i:G[v]) if(!A[i]) q.push(i), A[i]=A[v]+1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0,s,e;i<M;i++) {
        cin >> s >> e;
        G[s].push_back(e), G[e].push_back(s);
    }
    bfs();
    int cnt=0;
    for(int i=1;i<=N;i++) if(A[i]==2 || A[i]==3) cnt++;
    cout << cnt;
    return 0;
}