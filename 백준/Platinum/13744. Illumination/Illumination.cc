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
    int n, r, l; cin >> n >> r >> l;
    vector<pair<int,int>> v(l);
    for(auto &[x,y]:v) cin >> x >> y;

    _2_sat g(l+1);
    for(int i=1;i<=l;i++) for(int j=1;j<=l;j++) if(i!=j) {
        auto [ix,iy]=v[i-1];
        auto [jx,jy]=v[j-1];

        if(ix == jx || iy == jy) {
            int dst = max(abs(ix-jx), abs(iy-jy));
            if(dst <= 2*r) {
                if(ix^jx) g.add_2_sat(T(i), T(j));
                if(iy^jy) g.add_2_sat(F(i),F(j));
            }
        }
    }
    cout << g.valid_2_sat();
    return 0;
}