#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
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

bool chk(vector<pll> &e, vector<int> &f, int n) {
    dsu d(n+1);
    for(int i=0;i<e.size();i++) if(f[i]) d.merge(e[i].first,e[i].second);
    return d.same(1,n);
}

void sol(int tc) {
    int n,m; cin >> n >> m;
    vector<pll> e;
    vector<int> f(m);
    vector<array<int,3>> a;
    for(int i=0,u,v,l,r;i<m;i++) {
        cin >> u >> v >> l >> r;
        e.push_back({u,v});
        a.push_back({l,r,i});
    }
    int k; cin >> k;
    vector<int> salmon(k);
    for(int &i:salmon) cin >> i;
    sort(all(salmon)), sort(rall(a));

    priority_queue<pll> pq;
    int ans=0, prv=0;
    for(int i:salmon) {
        int ch=0;
        while(a.size() && a.back()[0] <= i) {
            auto [l,r,j] = a.back(); a.pop_back();
            pq.push({-r,j}), f[j]=1;
            ch=1;
        }
        while(pq.size() && -pq.top().first < i) {
            f[pq.top().second]=0, pq.pop();
            ch=1;
        }
        if(ch) prv = chk(e, f, n);
        ans += prv;
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