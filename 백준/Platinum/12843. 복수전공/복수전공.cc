#include <bits/stdc++.h>
using namespace std;

const int MAX_V=2020;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];
char C[MAX_V];

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
    for(int i=1;i<=N;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1,x;i<=N;i++) {
        char c; cin >> x >> c;
        C[x]=c=='c';
    }
    for(int i=0,u,v;i<M;i++) {
        cin >> u >> v;
        if(C[u] == C[v]) continue;
        if(C[u]) swap(u,v);
        G[u].push_back(v);
    }
    cout << N-matching();
    return 0;
}