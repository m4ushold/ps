#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<typename flow_t=int, typename cost_t=long long, flow_t MAX_U=(1<<30), cost_t MAX_C=(1LL<<60)>
struct MinCostFlow{ // 0-based
    struct edge_t{ int v, r; flow_t c; cost_t d; };
    int n;
    vector<vector<edge_t>> g;
    vector<int> prv, idx, chk;
    vector<cost_t> dst;
    MinCostFlow(int n) : n(n) { clear(); }
    void clear(){
        g = vector<vector<edge_t>>(n);
        prv = idx = chk = vector<int>(n);
        dst = vector<cost_t>(n);
    }
    void add_edge(int s, int e, flow_t c, cost_t d){
        g[s].push_back({e, (int)g[e].size(), c, d});
        g[e].push_back({s, (int)g[s].size()-1, 0, -d});
    }
    bool find_path(int s, int t){
        fill(chk.begin(), chk.end(), 0);
        fill(dst.begin(), dst.end(), MAX_C);
        queue<int> que; que.push(s); dst[s] = 0; chk[s] = 1;
        while(!que.empty()){
            int v = que.front(); que.pop(); chk[v] = 0;
            for(int i=0; i<g[v].size(); i++){
                const auto &e = g[v][i];
                if(e.c > 0 && dst[e.v] > dst[v] + e.d){
                    dst[e.v] = dst[v] + e.d; prv[e.v] = v; idx[e.v] = i;
                    if(!chk[e.v]) que.push(e.v), chk[e.v] = 1;
                }
            }
        }
        return dst[t] < MAX_C;
    }
    pair<flow_t, cost_t> augment(int s, int t, flow_t k=-1){
        if(!find_path(s, t)) return {0, 0};
        flow_t fl = MAX_U;
        for(int i=t; i!=s; i=prv[i]) fl = min(fl, g[prv[i]][idx[i]].c);
        if(k != -1) fl = min(fl, k);
        for(int i=t; i!=s; i=prv[i]){
            g[prv[i]][idx[i]].c -= fl;
            g[i][g[prv[i]][idx[i]].r].c += fl;
        }
        return {fl, fl * dst[t]};
    }
    pair<flow_t, cost_t> run(int s, int t, flow_t k=-1){
        flow_t flow = 0; cost_t cost = 0;
        while(true){
            auto [fl,cst] = augment(s, t, k);
            if(fl == 0) break;
            flow += fl; cost += cst;
            if(k != -1) k -= fl;
        }
        return {flow, cost};
    }
};

ll N, M, C[202][202], A[202], B[202];

void sol(int tc) {
    MinCostFlow<ll> flow(222);
    cin >> N >> M;
    int s=201, e=202;
    for(int i=1;i<=N;i++) cin >> A[i], flow.add_edge(i,e,A[i],0);
    for(int j=1;j<=M;j++) cin >> B[j], flow.add_edge(s,N+j,B[j],0);
    for(int i=1;i<=M;i++) for(int j=1;j<=N;j++) {
        cin >> C[j][i];
        flow.add_edge(N+i, j, 1e9, C[j][i]);
    }
    cout << flow.run(s,e).second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}