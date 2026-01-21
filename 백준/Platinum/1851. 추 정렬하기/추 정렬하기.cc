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
    vector<int> p, mv, s;
    dsu(int n) : p(n,-1), n(n), mv(n), s(n) {}
    int leader(int a) { return p[a] < 0 ? a : p[a] = leader(p[a]); }
    int size(int a) { return -p[leader(a)]; }
    bool same(int a, int b) { return leader(a) == leader(b); }
    int merge(int a, int b) {
        return (a = leader(a)) != (b = leader(b)) && (-p[a] < -p[b] ? swap(a,b) : void(), p[a]+=p[b], s[a]+=s[b], mv[a]=min(mv[a],mv[b]), p[b]=a, true);
    }
};

void sol(int tc) {
    int n; cin >> n;
    dsu d(n);
    vector<pll> v(n);
    int mg = 1e9;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        v[i] = {x,i};
        d.mv[i] = x;
        d.s[i] = x;
        mg = min(mg,x);
    }
    sort(all(v));

    for(int i=0;i<n;i++) d.merge(v[i].second, i);
    ll ans=0;
    for(int i=0;i<n;i++) if(i == d.leader(i)) {
        ll cnt = d.size(i);
        ans += min((cnt - 2) * d.mv[i] + d.s[i], mg * (cnt+1) + d.s[i] + d.mv[i]);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}