#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template <typename flow_t>
struct Dinic {
    struct edge_t {int v,r; flow_t c,f;};
    static const flow_t MAX_F=1<<30;
    int n;
    vector<vector<edge_t>> g;
    vector<int> lv, idx;
    Dinic(int n) : n(n) { 
        g=vector<vector<edge_t>>(n);
        lv=vector<int>(n);
        idx=vector<int>(n);
    }
    void addEdge(int s, int e, flow_t c1, flow_t c2=flow_t(0)) {
        g[s].push_back({e,g[e].size(),c1,0});
        g[e].push_back({s,g[s].size()-1,c2,0});
    }
    bool bfs(int s, int t, flow_t limit=1) {
        fill(lv.begin(),lv.end(),0);
        queue<int> q;
        q.push(s), lv[s]=1;
        while(!q.empty()) {
            int v=q.front(); q.pop();
            for(auto e:g[v]) if(!lv[e.v] && e.c-e.f>=limit) q.push(e.v), lv[e.v]=lv[v]+1;
        }
        return lv[t]!=0;
    }
    flow_t dfs(int v, int t, flow_t f1=MAX_F) {
        if(v==t || f1==flow_t(0)) return f1;
        for(int &i = idx[v] ; i< g[v].size();i++) {
            auto &e = g[v][i];
            if(lv[e.v] != lv[v]+1 || e.c-e.f==flow_t(0)) continue;
            flow_t now=dfs(e.v,t,min(f1,e.c-e.f));
            if(now==flow_t(0)) continue;
            e.f+=now, g[e.v][e.r].f-=now;
            return now;
        }
        return 0;
    }
    flow_t mf(int s, int t) {
        flow_t mf=0, f=0;
        while(bfs(s,t)) {
            fill(idx.begin(),idx.end(),0);
            while((f=dfs(s,t)) != flow_t(0)) mf+=f;
        }
        return mf;
    }
};

int N, A[505][505], R[505], C[505], I[505][505];

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) R[i]=i;
    for(int i=1;i<=N;i++) C[i]=N+i;
    int s = 0, e = 2*N+N*N+1, x = N+N, zc = 0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        cin >> A[i][j];
        I[i][j]=++x;
    }

    Dinic<int> dinic(e+1);
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        if(A[i][j] == 0) {
            zc++;
            dinic.addEdge(I[i][j], e, 1);
            dinic.addEdge(R[i], I[i][j], dinic.MAX_F);
            dinic.addEdge(C[j], I[i][j], dinic.MAX_F);
        } else if(A[i][j] > 1) {
            dinic.addEdge(s, I[i][j], A[i][j]-1);
            dinic.addEdge(I[i][j], R[i], dinic.MAX_F);
            dinic.addEdge(I[i][j], C[j], dinic.MAX_F);
        }
    }
    int c1 = dinic.mf(s,e);
    cout << (zc-c1)*2+c1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}