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
    vector<int> p, s;
    dsu(int n) : p(n,-1), n(n), s(n) {}
    int leader(int a) { return p[a] < 0 ? a : p[a] = leader(p[a]); }
    int size(int a) { return -p[leader(a)]; }
    int chaos(int a) { return (s[leader(a)] + 9) / 10 * 10; }
    bool same(int a, int b) { return leader(a) == leader(b); }
    int merge(int a, int b) {
        return (a = leader(a)) != (b = leader(b)) && (-p[a] < -p[b] ? swap(a,b) : void(), p[a]+=p[b], p[b]=a, s[a]+=s[b], true);
    }
};

void sol(int tc) {
    int n; cin >> n;
    dsu d(n);
    vector<int> a(n), v(n), f(n);
    for(int i=0;i<n;i++) cin >> a[i], d.s[i]=a[i];
    for(int &i:v) cin >> i;
    reverse(all(v));
    ll sum=0, mx=0, cnt=0;
    for(int i:v) {
        int s=0;
        if(i-2>=0 && f[i-2] && !d.same(i-2,i-1)) sum -= d.chaos(i-2), d.merge(i-2,i-1), ++s;
        if(i<n && f[i] && !d.same(i-1,i)) sum -= d.chaos(i), d.merge(i-1,i), ++s;
        cnt += 1 - s;
        sum += d.chaos(i-1);
        f[i-1]=1;
        mx = max(mx, cnt * sum);
    }
    cout << mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}