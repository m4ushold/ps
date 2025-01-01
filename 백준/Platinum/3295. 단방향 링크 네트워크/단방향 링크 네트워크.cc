#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1010;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];

bool dfs(int v)  {
    vi[v]=1;
    for(int i:G[v]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

int matching() {
    int cnt=0;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=0;i<=N;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

void sol() {
    for(int i=0;i<MAX_V;i++) G[i].clear();

    cin >> N >> M;
    for(int i=0,s,e;i<M;i++) {
        cin >> s >> e;
        G[s].push_back(e);
    }
    cout << matching() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}