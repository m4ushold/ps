#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=606*606;
int N, M, A[sz], B[sz], vi[sz];
char C[606][606];
vector<int> G[sz];

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
    for(int i=0;i<sz;i++) A[i]=B[i]=-1;
    for(int i=1;i<=N*N;i++) {
        for(int i=0;i<sz;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

bool chk(int i, int j) {
    return 1<=min(i,j) && max(i,j)<=N;
}

int idx(int i, int j) {
    return (i-1)*N+j;
}

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> C[i][j];
    vector<pair<int,int>> dir({
        {1,0}, {0,1}, {0,-1}, {-1,0}
    });
    int ans=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(((i+j)&1) && C[i][j] == '#') {
        for(auto [di,dj]:dir) if(chk(i+di, j+dj) && C[i+di][j+dj] == '#') G[idx(i,j)].push_back(idx(i+di,j+dj));
    }
    cout << "Case " << tc << ": " << matching() << '\n';

    for(int i=1;i<=N*N;i++) G[i].clear();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}