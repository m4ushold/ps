#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[202020], B[202020], C[202020];
ll D[2][202020], E[202020];
vector<int> V;

void dfs(int v, int d=0) {
    if(C[v]) return;
    V.push_back(v);
    C[v]=1, dfs(A[v],d+1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<tuple<int,int,int>> v(n);
    for(auto &[a,b,c]:v) cin >> a >> b >> c;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        auto [a,b,c]=v[i];
        A[i+1]=b, B[i+1]=c;
    }
    ll res=0;
    for(int i=1;i<=n;i++) if(!C[i]) {
        dfs(i);
        for(int j=1;j<=V.size();j++) E[j]=B[V[j-1]];
        
        D[0][1]=1e9, D[1][1]=E[1];
        for(int i=2;i<=V.size();i++) {
            D[0][i]=D[1][i-1];
            D[1][i]=min(D[0][i-1],D[1][i-1])+E[i];
        }
        ll t=min(D[0][V.size()], D[1][V.size()]);

        D[0][1]=0, D[1][1]=1e9;
        for(int i=2;i<=V.size();i++) {
            D[0][i]=D[1][i-1];
            D[1][i]=min(D[0][i-1],D[1][i-1])+E[i];
        }
        res+=min(t,D[1][V.size()]);
        V.clear();
    }
    cout << res;
    
    return 0;
}