#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

struct dsu {
    int n;
    vector<int> p;
    dsu(int n) : p(n,-1), n(n) {}
    int leader(int a) { return p[a] < 0 ? a : p[a] = leader(p[a]); }
    int size(int a) { return -p[leader(a)]; }
    bool same(int a, int b) { return leader(a) == leader(b); }
    int merge(int a, int b) {
        return (a = leader(a)) != (b = leader(b)) && (-p[a] < -p[b] ? swap(a,b) : void(), p[a]+=p[b], p[b]=a, true);
    }
};

int A[101010];
vector<int> G[101010], V[101010];

void sol(int tc) {
    int n; cin >> n;
    for(int i=1,u,v;i<n;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    dsu d(n+1);
    queue<int> q;
    q.push(1), q.push(2);
    while(q.size()) {
        int v = q.front(); q.pop();
        for(int i:G[v]) if(A[i]==0 && i>2) q.push(i), A[i] = A[v] + 1;
    }
    for(int i=1;i<=n;i++) V[A[i]].push_back(i);
    ll ans = 0, cnt = 0;
    for(int i=n-1;i;i--) {
        for(int j:V[i]) {
            for(int k:G[j]) if(A[k]>=i) {
                if(d.same(j,k) == false) {
                    cnt += (ll)d.size(j) * d.size(k);
                    d.merge(j,k);
                }
            }
        }
        ans += cnt;
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}