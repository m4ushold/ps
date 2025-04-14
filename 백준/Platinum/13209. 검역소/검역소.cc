#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, K, A[1<<17];
vector<int> G[1<<17];

pair<ll,ll> dfs(int v=1, int p=-1, ll m=0) {
    ll cnt=0, a=A[v];
    vector<ll> vec;
    for(int i:G[v]) if(i!=p) {
        auto [c, x] = dfs(i,v,m);
        cnt+=c, a+=x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    while(vec.size() && a>m) {
        a-=vec.back(), vec.pop_back(), cnt++;
    }
    return {cnt, a};
}

void sol() {
    cin >> N >> K;
    ll l=0, r=1e15;
    for(int i=1;i<=N;i++) G[i].clear(), cin >> A[i], l=max(l,A[i]);
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);

    while(l<r) {
        ll m=l+r>>1;
        if(dfs(1,-1,m).first <= K) r=m;
        else l=m+1;
    }
    cout << l << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}