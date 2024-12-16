#include <bits/stdc++.h>
using namespace std;

const int MAX_V=505;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];

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

int matching() {
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    int cnt=0;
    for(int i=1;i<=N;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0,a,b;i<M;i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }
    cout << matching();
    return 0;
}