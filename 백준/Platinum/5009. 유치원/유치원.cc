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

constexpr int sz = 202;
int N, A[sz], B[sz][sz];

int a(int x) {
    return (A[x]+1)%3;
}

int c(int a, int b) {
    if(min(a,b) == 1) return 0;
    else if(max(a,b) == 1) return 2;
    return 1;
}

bool chk(int t) {
    _2_sat s(N+1);
    for(int i=1;i<=N;i++) {
        for(int j=t+1;j<N;j++) {
            if(A[i] == A[B[i][j]]) s.add_2_sat(T(i), T(B[i][j])), s.add_2_sat(F(i), F(B[i][j]));
            else {
                int k = c(A[i], A[B[i][j]]);
                int aa = a(i) == k ? T(i) : F(i), bb = a(B[i][j]) == k ? T(B[i][j]) : F(B[i][j]);
                s.add_2_sat(rev(aa), rev(bb));
            }
       }
    }

    return s.valid_2_sat();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        for(int j=1;j<N;j++) cin >> B[i][j];
    }

    int l=0, r=N-1;
    while(l<r) {
        int m=l+r>>1;
        if(chk(m)) r=m;
        else l=m+1;
    }
    cout << r;
    
    return 0;
}