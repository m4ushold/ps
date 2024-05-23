#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, C, IN[101010], D[101010];
vector<pair<int,int>> G[101010];

void tSort()
{
    queue<int> q;
    for(int i=1;i<=N;i++) if (!IN[i]) q.push(i);
    while(!q.empty()) {
        int v=q.front(); q.pop();
        for(auto [i,w] : G[v]) {
            IN[i]--;
            D[i]=max(D[i],D[v]+w);
            if (!IN[i]) q.push(i);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> C;
    for(int i=1;i<=N;i++) cin >> D[i];
    for(int i=0,a,b,w;i<C;i++) cin >> a >> b >> w, IN[b]++, G[a].push_back({b,w});
    tSort();
    for(int i=1;i<=N;i++) cout << D[i] << '\n';
    return 0;
}