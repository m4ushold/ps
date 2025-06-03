#include <bits/stdc++.h>
using namespace std;

const int sz = 20202, inf = 1e9;
map<pair<int,int>, int> C, F;
vector<int> G[sz];

int mxf(int s, int t) {
    int mf=0;
    while(1) {
        vector<int> par(sz,-1);
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int v=q.front(); q.pop();
            for(int i:G[v]) if(C[{v,i}]-F[{v,i}]>0 && par[i]==-1) {
                q.push(i), par[i]=v;
                if(i==t) break;
            }
        }
        if(par[t]==-1) break;

        int mn=1e9;
        for(int i=t;i!=s;i=par[i]) mn=min(mn, C[{par[i],i}]-F[{par[i],i}]);
        for(int i=t;i!=s;i=par[i]) F[{par[i],i}]+=mn, F[{i,par[i]}]-=mn;
        mf+=mn;
    }
    return mf;
}

int N, M, I[101][101];
char A[101][101];
vector<pair<int,int>> dir({{-1,0},{0,-1}});

bool chk(int x, int y) {
    return 1<=min(x,y) && x<=N && y<=M;
}

void addEdge(int s, int e, int w) {
    G[s].push_back(e);
    G[e].push_back(s);
    C[{s,e}]=w;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    int s=0, t=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        cin >> A[i][j];
        I[i][j]=(i-1)*M + j;
        addEdge(I[i][j] * 2, I[i][j] * 2 + 1, 1);
        if(A[i][j] == 'K') s = I[i][j] * 2 + 1;
        if(A[i][j] == 'H') t = I[i][j] * 2;
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j] != '#') {
        for(auto [dx,dy]:dir) {
            if(chk(i+dx,j+dy) && A[i+dx][j+dy] != '#') {
                addEdge(I[i][j] * 2 + 1, I[i+dx][j+dy] * 2, inf);
                addEdge(I[i+dx][j+dy] * 2 + 1, I[i][j] * 2, inf);
            }
        }
    }
    int res = mxf(s,t);
    if(res >= inf) cout << -1;
    else cout << res;
    return 0;
}