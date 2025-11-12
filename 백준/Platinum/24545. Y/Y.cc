#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, D[101010], DD[101010], R;
vector<int> G[101010];

void dfs(int v=1, int p=-1) {
    D[v]=1;
    for(int i:G[v]) if(i!=p) {
        dfs(i,v);
        D[v] = max(D[v], D[i] + 1);
    }
}

void dfs2(int v=1, int p=-1, int w=0) {
    if(G[v].size() == 1 && G[v][0] == p) return;

    vector<pll> vec;
    for(int i:G[v]) if(i!=p) vec.push_back({D[i],i});
    if(p!=-1) vec.push_back({w,p});
    sort(rall(vec));
    if(vec.size()>=3) R=max<int>(R, vec[0].first+vec[1].first+vec[2].first+1);

    auto [a,ai] = vec[0];
    for(int i:G[v]) if(i!=p) {
        if(i == ai) {
            if(vec.size()>1) dfs2(i, v, vec[1].first + 1);
            else dfs2(i,v,1);
        }
        else dfs2(i, v, a+1);
    }
}

void sol(int tc) {
    cin >> N;
    for(int i=1;i<N;i++) {
        int a,b; cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }
    dfs(), dfs2();
    cout << R;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}