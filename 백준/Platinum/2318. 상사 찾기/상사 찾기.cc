#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

vector<int> G[30303];
int D[30303], P[30303];

void dfs(int v=0) {
    D[v]=1;
    for(int i:G[v]) {
        dfs(i);
        D[v]+=D[i];
        P[i]=v;
    }
}

void sol(int tc) {
    int n,m; cin >> n >> m;
    map<int,int> id, sal, rid;
    vector<pll> v;
    for(int i=0;i<n;i++) {
        int a,b,c; cin >> a >> b >> c;
        id[a]=i+1;
        rid[i+1]=a;
        sal[b]=a;
        v.push_back({c,b});
    }
    sort(rall(v));
    set<int> s;
    for(auto [ti,sa]:v) {
        int i = sal[sa];
        if(s.empty()) G[0].push_back(id[i]);
        else {
            int ss = *s.upper_bound(sa);
            G[id[sal[ss]]].push_back(id[i]);
        }
        s.insert(sa);
    }

    dfs();
    for(int i=0;i<m;i++) {
        int x; cin >> x;
        cout << rid[P[id[x]]] << ' ' << D[id[x]]-1 << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}