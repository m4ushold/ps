#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, D[101], C[101];
vector<int> G[101];
double R;

void dfs(int v=0, int p=-1) {
    for(int i:G[v]) if(i!=p) {
        dfs(i,v);
        D[v]+=D[i];
        C[v]+=C[i];
    }
    if(p!=-1) {
        R += pow((double)(N-C[v])/(N-1), D[v]) * pow((double)C[v]/(N-1), M-D[v]);
    }
}

void sol(int tc) {
    cin >> N >> M;
    C[0]=1;
    for(int i=1,a,b;i<N;i++) {
        cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
        C[i]=1;
    }
    for(int i=0;i<M;i++) {
        int x; cin >> x;
        D[x]++;
    }
    dfs();
    cout << fixed << setprecision(12) << R;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}