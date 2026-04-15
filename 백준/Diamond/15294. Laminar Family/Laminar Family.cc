#include <bits/stdc++.h>
using namespace std;

const int sz=1<<17;
int N, M, D[sz], P[sz], ID[sz], IDX[sz], V[sz], OC[sz];
vector<int> G[sz], T[sz], X[sz];
vector<array<int,3>> A[sz];

void dfs(int v=1, int p=-1) {
    for(int i:G[v]) if(i!=p) {
        P[i]=v;
        dfs(i,v);
        D[v]^=D[i];
    }
}

void dfs2(int v, int id, int p=-1, int idx=1) {
    X[id].push_back(v);
    ID[v] = id;
    IDX[v] = idx;
    V[v] = 1;
    for(int i:T[v]) if(i!=p) {
        dfs2(i,id,v,idx+1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(INT_MIN, INT_MAX);

    vector<pair<int,int>> edges(M);
    for(auto &[u,v]:edges) {
        cin >> u >> v;
        if(u>v) swap(u,v);
        int x = distrib(gen);
        D[u]^=x, D[v]^=x;
    }
    sort(edges.begin(),edges.end());
    edges.erase(unique(edges.begin(),edges.end()),edges.end());

    dfs();
    for(int i=2;i<=N;i++) if(D[i]) T[i].push_back(P[i]), T[P[i]].push_back(i);
    
    for(int i=1;i<=N;i++) {
        if(T[i].size() >= 3) return cout << "No", 0;
    }

    vector<int> vec;
    for(int i=1;i<=N;i++) if(T[i].size() == 1) vec.push_back(i);
    for(int i=0,id=1;i<vec.size();i++) if(V[vec[i]] == 0) dfs2(vec[i], id++);

    int aa=1, ans=1;
    for(auto [u,v]:edges) {
        if(u==v) continue;
        if(IDX[u] > IDX[v]) swap(u,v);
        int len = abs(IDX[u] - IDX[v]) + 1;
        A[u].push_back({len,aa,1});
        A[v].push_back({len,aa,-1});
        if(OC[u]==-1 || OC[v]==1) ans=0;
        OC[u] = 1, OC[v] = -1;
        aa++;
    }
    if(ans==0) return cout << "No", 0;

    for(int i=1;i<=N;i++) if(OC[i]) {
        if(OC[i] == 1) {
            sort(A[i].begin(), A[i].end(), greater<>());
        } else {
            sort(A[i].begin(),A[i].end());
        }
    }

    for(int i=1;i<sz;i++) if(X[i].size()) {
        stack<int> stk;
        for(auto v:X[i]) {
            for(auto [len,a,op]:A[v]) {
                if(op == 1) stk.push(a);
                else if(stk.empty() || stk.top() != a) ans=0;
                else stk.pop();
            }
        }
    }
    cout << (ans ? "Yes" : "No");
    return 0;
}