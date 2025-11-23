#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, C[10101];
vector<int> G[10101], R[10101], V;
vector<vector<int>> S;

void dfs1(int v) {
    C[v]=-1;
    for(auto i:G[v]) if(!C[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c) {
    C[v]=c; S.back().push_back(v);
    for(auto i:R[v]) if(C[i]==-1) dfs2(i,c);
}

int getSCC() {
    for(int i=1;i<=N;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) S.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

void sol(int tc) {
    for(int i=1;i<=N;i++) G[i].clear(), R[i].clear(), C[i]=0;
    V.clear(), S.clear();

    for(int i=0;i<M;i++) {
        int a,b,c; cin >> a >> b >> c;
        if(c==1) G[a].push_back(b), R[b].push_back(a);
        else G[a].push_back(b), G[b].push_back(a), R[a].push_back(b), R[b].push_back(a);
    }
    cout << (getSCC() == 1) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while(cin >> N >> M && N) sol(1);
    return 0;
}