#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, F[101010], R;
vector<int> G[101010];

ll dfs(int v=0) {
    if(G[v].empty()) return F[v];
    ll mn=LLONG_MAX;
    for(int i:G[v]) {
        ll x = dfs(i);
        mn = min(mn, x);
        R += x;
    }
    if(v) R-=mn;
    return max(F[v], mn);
}

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> F[i], G[i].clear();
    G[0].clear();
    for(int i=1,p;i<=N;i++) cin >> p, G[p].push_back(i);
    R=0;
    dfs();
    cout << "Case #" << tc << ": " << R << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}