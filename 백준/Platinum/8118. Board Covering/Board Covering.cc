#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

const int MAX_V=3030;
int N, A[MAX_V], B[MAX_V], vi[MAX_V], C[55][55], I[55][55];
vector<int> G[MAX_V];
vector<pll> dir({
    {1,0},{0,1},{-1,0},{0,-1}
});

bool dfs(int v) {
    vi[v]=1;
    for(int i:G[v]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

int bi_matching() {
    int cnt=0;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=1;i<=N*N;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

void sol(int tc) {
    int a,b,c; cin >> N >> a >> b >> c;
    for(int i=0;i<55;i++) for(int j=0;j<55;j++) C[i][j]=1;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        I[i][j] = (i-1)*N+j;
        C[i][j] = I[i][j] == a || I[i][j] == b || I[i][j] == c;
    }
    
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(C[i][j]==0 && ((i+j)&1)) {
        for(auto [dx,dy]:dir) {
            int ni = i+dx,nj=j+dy;
            if(C[ni][nj] == 0 && (~(ni+nj)&1)) {
                G[I[i][j]].push_back(I[ni][nj]);
            }
        }
    }
    if(bi_matching() == (N*N-3)/2) {
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(A[I[i][j]]!=-1 && ((i+j)&1)) cout << I[i][j] << " " << A[I[i][j]] << endl;
    } else cout << "NIE";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}