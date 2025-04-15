#include <bits/stdc++.h>
using namespace std;

const int MAX_V=101;
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
    for(int i=0;i<MAX_V;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
        if(cnt == N) return i+1;
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        for(int i=0;i<MAX_V;i++) G[i].clear();

        cin >> N >> M;
        for(int i=1,s,e,n;i<=M;i++) {
            cin >> s >> e >> n;
            for(int j=0,x;j<n;j++) {
                cin >> x;
                for(int k=s;k<e;k++) G[k].push_back(x);
            }
        }
        cout << matching() << '\n';
    }

    return 0;
}