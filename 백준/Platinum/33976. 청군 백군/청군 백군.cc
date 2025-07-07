#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int T(int k){return k << 1;}
int F(int k){return k << 1 | 1;}
int rev(int k){return k ^ 1;}
struct _2_sat{
    int n, cnt;
    vector<vector<int>>G, scc;
    vector<int> id, fin, S, scc_id, cc;
    _2_sat(int k){ // 0 ~ n-1
        n = k;
        cnt = 0;
        G = vector<vector<int>>(n << 1 | 1);
        cc = vector<int>(n << 1 | 1);
    }
    void st() {
        for(int i=0;i<cc.size();i++) cc[i] = G[i].size();
    }
    void cl() {
        for(int i=0;i<G.size();i++) {
            while(G[i].size() > cc[i]) G[i].pop_back();
        }
    }
    int dfs(int v){
        int Top = id[v] = ++cnt;
        S.push_back(v);
        for(int nx : G[v]){
            if(!id[nx])Top = min(Top, dfs(nx));
            else if(!fin[nx])Top = min(Top, id[nx]);
        }
        if(Top == id[v]){
            vector<int>tmp;
            while(S.size()){
                int nx = S.back(); S.pop_back();
                fin[nx] = 1; tmp.push_back(nx);
                scc_id[nx] = scc.size();
                if(nx == v)break;
            }
            scc.push_back(tmp);
        }
        return Top;
    }
    void add_2_sat(int u,int v){ // T 나 F 씌워서 주기 
        G[rev(u)].push_back(v);
        G[rev(v)].push_back(u);
    }
    bool valid_2_sat(){
        id = fin = scc_id = vector<int>(n<<1|1);
        for(int s=0; s<(n<<1); s++)if(!id[s]) dfs(s);
        for(int s=0; s<n; s++)if(scc_id[T(s)] == scc_id[F(s)])return 0;
        return 1;
    };
    vector<bool> get_2_sat(){
        vector<bool>tmp(n);
        for(int s=0; s<n; s++)tmp[s] = scc_id[T(s)] < scc_id[F(s)];
        return tmp;
    }
};

int A[505][505];

bool chk(_2_sat &cnf, int x, int n) {
    cnf.cl();
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {
        if(A[i][j] < x) cnf.add_2_sat(T(i), T(j)), cnf.add_2_sat(F(i), F(j));
    }
    return cnf.valid_2_sat();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    _2_sat cnf(n+1);
    for(int i=0;i<m;i++) {
        int x; cin >> x;
        vector<int> v(x);
        for(int &j:v) cin >> j;
        for(int j=0;j<x;j++) for(int k=j+1;k<x;k++) cnf.add_2_sat(T(v[j]), T(v[k]));
    }
    for(int i=0;i<k;i++) {
        int x; cin >> x;
        vector<int> v(x);
        for(int &j:v) cin >> j;
        for(int j=0;j<x;j++) for(int k=j+1;k<x;k++) cnf.add_2_sat(F(v[j]), F(v[k]));
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> A[i][j];
    cnf.st();

    int l=0, r=1e9+1;
    while(l<r) {
        int m=l+r+1>>1;
        if(chk(cnf, m, n)) l=m;
        else r=m-1;
    }
    if(l > (int)1e9) cout << "INFINITY";
    else cout << l;

    return 0;
}