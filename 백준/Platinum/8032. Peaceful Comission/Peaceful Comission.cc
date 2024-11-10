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
    vector<int>id, fin, S, scc_id;
    _2_sat(int k){ // 0 ~ n-1
        n = k;
        cnt = 0;
        G = vector<vector<int>>(n << 1 | 1);
        id = fin = scc_id = vector<int>(n << 1 | 1);
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
        for(int s=0; s<(n<<1); s++)if(!id[s])dfs(s);
        for(int s=0; s<n; s++)if(scc_id[T(s)] == scc_id[F(s)])return 0;
        return 1;
    };
    vector<bool> get_2_sat(){
        vector<bool>tmp(n);
        for(int s=0; s<n; s++)tmp[s] = scc_id[T(s)] < scc_id[F(s)];
        return tmp;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    _2_sat cnf(2*n);
    
    for(int i=0;i<2*n;i+=2) cnf.add_2_sat(T(i), T(i+1)), cnf.add_2_sat(F(i), F(i+1));
    for(int i=1,b,a;i<=m;i++) {
        cin >> a >> b;
        cnf.add_2_sat(F(a-1), F(b-1));
    }
    
    if(cnf.valid_2_sat()) {
        auto v = cnf.get_2_sat();
        for(int i=0;i<v.size();i++) if(v[i]) cout << i+1 << '\n';
    } else cout << "NIE";
    return 0;
}