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
    int n,m;
    string s;
    cin >> n >> m >> s;
    _2_sat cnf(3*n);
    for(int i=0;i<n;i++) {
        int a=i*3,b=i*3+1,c=i*3+2;
        if(s[i] == 'G') swap(a,b);
        else if(s[i] == 'B') swap(a,c);
        cnf.add_2_sat(F(a),F(a));
        cnf.add_2_sat(T(b),T(c)), cnf.add_2_sat(F(b),F(c));
    }

    for(int i=0;i<m;i++) {
        int u,v; cin >> u >> v;
        u--, v--;
        for(int j=0;j<3;j++) {
            cnf.add_2_sat(F(u*3+j),F(v*3+j));
        }
    }
    if(!cnf.valid_2_sat()) {
        cout << "Impossible";
    } else {
        auto v = cnf.get_2_sat();
        for(int i=0;i<n;i++) {
            if(v[i*3]) cout << 'R';
            else if(v[i*3+1]) cout << 'G';
            else cout << 'B';
        }
    }
    return 0;
}