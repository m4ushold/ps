#include <bits/stdc++.h>
using namespace std;

constexpr int sz=303;
int N, M, A[sz], B[sz], vi[sz], MX[sz], GG[sz][sz];
vector<int> G[sz];
string S[sz];

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
    for(int i=1;i<=N;i++) {
        for(int i=0;i<sz;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    map<string,int> id;
    for(int i=1;i<=N;i++) {
        cin >> S[i];
        id[S[i]] = i;
        MX[i]=1;
    }
    memset(GG, 1, sizeof(GG));
    cin >> M;
    for(int i=0;i<M;i++) {
        int m,w; cin >> m >> w;
        vector<int> tmp(N+1);
        for(int j=0;j<m;j++) {
            string s; cin >> s;
            int k = id[s];
            tmp[k]=1;
            MX[k]=max(MX[k], w);
        }
        for(int i=1;i<=N;i++) if(tmp[i]==0) GG[i][w]=0;
    }
    for(int i=1;i<=N;i++) for(int j=1;j<MX[i];j++) GG[i][j]=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(GG[i][j]) G[i].push_back(j);
    matching();
    for(int i=1;i<=N;i++) {
        cout << S[B[i]] << ' ';
    }

    return 0;
}