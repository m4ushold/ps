#include <bits/stdc++.h>
using namespace std;

const int sz=55;
int N, C1, C2, C[sz][sz], A[sz], B[sz], vi[sz], D[sz][sz];
vector<int> G[sz];

bool dfs(int v)  {
    vi[v]=1;
    for(int i=1;i<=N;i++) if(D[v][i]) {
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
    for(int i=1;i<=N;i++) {
        for(int i=0;i<sz;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int ord_matching() {
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) D[i][j]=C[i][j];

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) D[i][j]=0;
        for(int j=1;j<=N;j++) if(C[i][j]) {
            D[i][j]=1;

            if(matching() == N) {
                break;
            }

            D[i][j]=0;
        }
    }

    return matching();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> C1 >> C2;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) C[i][j]=1;
    for(int i=1,l,r,m;i<=C1;i++) {
        cin >> l >> r >> m;
        for(int j=1;j<=N;j++) {
            if(l<=j && j<=r) for(int k=1;k<m;k++) C[j][k]=0;
            else C[j][m]=0;
        }
    }
    for(int i=1,l,r,m;i<=C2;i++) {
        cin >> l >> r >> m;
        for(int j=1;j<=N;j++) {
            if(l<=j && j<=r) for(int k=m+1;k<=N;k++) C[j][k]=0;
            else C[j][m]=0;
        }
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(C[i][j]) G[i].push_back(j);

    // bipartite matching
    if(ord_matching() == N) for(int i=1;i<=N;i++) cout << A[i] << ' ';
    else cout << -1;
    return 0;
}