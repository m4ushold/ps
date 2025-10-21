#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, L[2020], R[2020], C[2020];
vector<int> G[2020];

int dfs(int v) {
    int res=0;
    for(int i:G[v]) {
        if(!C[i]) C[i]=C[v]==1?2:1, res|=dfs(i);
        else if(C[i] == C[v]) return 1;
    }
    return res;
}

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=2*N;i++) {
        char c; cin >> c;
        int x; cin >> x;
        if(c == '+') L[x]=i;
        else R[x]=i;
    }
    for(int i=1;i<=N;i++) for(int j=i+1;j<=N;j++) {
        int u = i, v = j;
        if(L[u] > L[v]) swap(u,v);
        if(L[v] < R[u] && R[u] < R[v]) G[u].push_back(v), G[v].push_back(u);
    }
    for(int i=1;i<=N;i++) if(!C[i]) {
        C[i]=1;
        if(dfs(i)) {
            cout << '*';
            return;
        }
    }
    for(int i=1;i<=N;i++) cout << (C[i]==1?'G':'S');
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}