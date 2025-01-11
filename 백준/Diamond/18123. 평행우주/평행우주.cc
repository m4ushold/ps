#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int S[33];
vector<int> G[33], cent;

void get_cent(int sz, int v=0, int p=-1) {
    S[v]=1;
    for(int i:G[v]) if(i!=p) {
        get_cent(sz,i,v);
        if(S[i] > sz/2) break;
        S[v]+=S[i];
    }
    if(sz-S[v] <= sz/2) cent.push_back(v);
}
ll tree(int v, int p=-1) {
    ll res=1;
    vector<ll> vec;
    for(int i:G[v]) if(i!=p) vec.push_back(tree(i,v));
    sort(vec.begin(),vec.end());
    for(ll i:vec) res<<=(64-__builtin_clzll(i)), res|=i;
    return res<<1;
}

ll sol() {
    for(int i=0;i<33;i++) S[i]=0, G[i].clear();
    cent.clear();

    int n; cin >> n;
    for(int i=1,u,v;i<n;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    get_cent(n);
    ll res=0;
    for(int i:cent) res=max(res,tree(i));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    vector<ll> dap;
    while(t--) dap.push_back(sol());
    sort(dap.begin(),dap.end());
    cout << distance(dap.begin(), unique(dap.begin(),dap.end()));
    return 0;
}