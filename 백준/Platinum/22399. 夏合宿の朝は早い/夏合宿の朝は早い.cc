#include <bits/stdc++.h>
using namespace std;

const int MAX_V=101;
int N, M, C[MAX_V];
double A[MAX_V];
vector<int> G[MAX_V], R[MAX_V], V;
vector<vector<int>> S;

void dfs1(int v)
{
    C[v]=-1;
    for(auto i:G[v]) if(!C[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c)
{
    C[v]=c; S.back().push_back(v);
    for(auto i:R[v]) if(C[i]==-1) dfs2(i,c);
}

int getSCC()
{
    for(int i=1;i<=N;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) S.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> N && N) {
        for(int i=0;i<MAX_V;i++) G[i].clear(), R[i].clear(), C[i]=0;
        S.clear(), V.clear();
        for(int i=1,m,a;i<=N;i++) {
            cin >> A[i] >> m;
            while(m--) cin >> a, G[i].push_back(a), R[a].push_back(i);
        }
        int n=getSCC();
        vector<int> in(n+1);
        for(int i=1;i<=N;i++) for(int j:G[i]) in[C[j]]+=(C[i]!=C[j]);

        double ans=1;
        for(int i=1;i<=n;i++) if(!in[i]) {
            double res=1;
            for(int j:S[i-1]) res*=A[j];
            ans*=1-res;
        }
        cout << fixed << setprecision(12) << ans << '\n';
    }
    return 0;
}