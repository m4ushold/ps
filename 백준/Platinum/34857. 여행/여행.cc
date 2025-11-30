#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
 
constexpr int sz = 1<<20;
int N, M, C[sz], A[sz], B[sz], I[sz], L[sz], CC[sz];
vector<pll> T[sz];
vector<int> G[sz], R[sz], V;
vector<vector<int>> S;
 
void dfs1(int v) {
    C[v]=-1;
    for(auto i:G[v]) if(!C[i]) dfs1(i);
    V.push_back(v);
}
 
void dfs2(int v, int c) {
    C[v]=c; S.back().push_back(v);
    for(auto i:R[v]) if(C[i]==-1) dfs2(i,c);
}
 
int getSCC() {
    for(int i=1;i<=N*10;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) S.emplace_back(), dfs2(i,++cnt);
    return cnt;
}
 
void connect(int a, int b) {
    G[a].push_back(b);
    R[b].push_back(a);
}
 
void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i] >> B[i];
    vector<array<int,3>> edge;
    for(int i=0;i<M;i++) {
        int a,b,c; cin >> a >> b >> c;
        edge.push_back({a,b,c});
        int aa = a*10 + CC[a];
        int bb = b*10 + CC[b];
        I[bb]=1;
        L[bb]=c, L[aa]=c;
        CC[a]++, CC[b]++;
        connect(aa,bb);
    }
 
    for(int i=1;i<=N;i++) {
        for(int j=0;j<CC[i];j++) for(int k=0;k<CC[i];k++) {
            int aa = i*10+j, bb = i*10+k, g = gcd(A[i], B[i]);
            if(I[aa] == 0 || I[bb] == 1) continue;
            if(L[aa] == L[bb]) connect(aa,bb);
            else if(L[aa] > L[bb]) {
                if((L[aa]-L[bb])%g == 0) connect(aa,bb);
            } else if(L[aa] < L[bb]) {
                if((L[bb]-L[aa])%g == 0) connect(aa,bb);
            }
        }
    }
    getSCC();
    for(auto v:S) {
        vector<int> vv;
        for(int i:v) vv.push_back(i/10);
        prs(vv);
        if(vv.size() == N) {
            for(int i=1;i<=N;i++) cout << 1 << endl;
            return;
        }
    }
    for(int i=0;i<N;i++) cout << 0 << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}