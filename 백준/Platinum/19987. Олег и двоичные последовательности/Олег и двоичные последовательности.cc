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
    pair<bool,int> valid_2_sat(){
        int cnt=0;
        for(int s=0; s<(n<<1); s++)if(!id[s])dfs(s), cnt++;
        for(int s=0; s<n; s++)if(scc_id[T(s)] == scc_id[F(s)])return {0,cnt};
        return {1, cnt};
    };
    vector<bool> get_2_sat(){
        vector<bool>tmp(n);
        for(int s=0; s<n; s++)tmp[s] = scc_id[T(s)] < scc_id[F(s)];
        return tmp;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    _2_sat cnf(n);
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        if(i==0) {
            if(x!=-1 && x!=0) return cout << 0, 0;
        }
        if(i==0 || x==-1) continue;
        if(x >= n) return cout << 0, 0;
        for(int j=0;j<x && i+j<n;j++) {
            cnf.add_2_sat(T(i+j), F(j));
            cnf.add_2_sat(F(i+j), T(j));
        }
        if(i+x<n) {
            cnf.add_2_sat(T(i+x), T(x));
            cnf.add_2_sat(F(i+x), F(x));
        }
    }
    auto [f, cnt] = cnf.valid_2_sat();
    if(f) {
        ll ans=1, mod=1e9+7;
        for(int i=0;i<cnt/2;i++) ans=ans*2%mod;
        cout << ans;
    } else {
        cout << 0;
    }
    return 0;
}