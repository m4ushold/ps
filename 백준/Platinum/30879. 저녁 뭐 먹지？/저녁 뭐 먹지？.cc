#include <bits/stdc++.h>
using namespace std;

int T(int k){return k << 1;}
int F(int k){return k << 1 | 1;}
int rev(int k){return k ^ 1;}
int I(int x) {return x>0 ? T(x) : F(abs(x));}

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

vector<tuple<int,int,int>> Q;

bool chk(int m) {
    _2_sat g(1<<17);
    for(int i=0;i<m;i++) {
        auto [a,b,c]=Q[i];
        if(a==1) g.add_2_sat(I(b),I(c));
    }
    return g.valid_2_sat();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> idx;
    for(int i=0,a,b,c;i<n;i++) {
        cin >> a;
        if(a==1) cin >> b >> c;
        else idx.push_back(i);
        Q.push_back({a,b,c});
    }

    int l=0, r=idx.size()-1;
    while(l<r) {
        int m=l+r+1>>1;
        if(chk(idx[m])) l=m;
        else r=m-1;
    }
    if(!chk(idx[l])) l--;
    
    for(int i=0;i<=l;i++) cout << "YES DINNER\n";
    for(int i=l+1;i<idx.size();i++) cout << "NO DINNER\n";
    return 0;
}