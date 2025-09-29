#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;

int N, K, A[101010];
vector<int> G[101010];

void dfs(int v) {
    if(G[v].empty()) {
        A[v]=1;
        return;
    }
    int mx=-1, idx=-1;
    for(int i:G[v]) {
        dfs(i);
        if(mx < A[i]) mx=A[i], idx=i;
    }
    A[v]=mx+1, A[idx]=0;
}

void solve(){
    cin >> N >> K;
    vector<ll> v(K);
    for(ll &i:v) cin >> i;
    for(int i=1;i<N;i++) {
        int p; cin >> p;
        G[p].push_back(i);
    }
    dfs(0);
    vector<ll> a;
    for(int i=0;i<N;i++) if(A[i]) a.push_back(A[i]);
    sort(v.begin(),v.end());
    sort(a.begin(),a.end());

    ll ans=0;
    for(int i=0;i<K;i++) ans += v[i]*a[i];
    cout << ans-v.back();
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();

}