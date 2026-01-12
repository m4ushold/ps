#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int N, M, K, R[1010101], D[5050][2];
vector<int> G[5050];
vector<array<int,3>> Q[5050];

void sol(int tc) {
    cin >> N >> M >> K;
    for(int i=0,u,v;i<M;i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0,a,b,c;i<K;i++) {
        cin >> a >> b >> c;
        Q[a].push_back({b,c,i});
    }

    for(int s=1;s<=N;s++) if(Q[s].size()) {
        memset(D, 0, sizeof(D));

        queue<pii> q;
        q.push({s,0});
        D[s][0]=1;
        while(q.size()) {
            auto [v,f] = q.front(); q.pop();
            for(int i:G[v]) if(D[i][f^1] == 0) {
                D[i][f^1] = D[v][f] + 1;
                q.push({i,f^1});
            }
        }

        for(auto [b,c,i]:Q[s]) {
            if(s == b && c > 0 && G[s].empty()) R[i] = 0;
            else R[i] = D[b][c&1] > 0 && D[b][c&1] - 1 <= c;
        }
    }
    for(int i=0;i<K;i++) cout << (R[i] ? "TAK" : "NIE") << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}