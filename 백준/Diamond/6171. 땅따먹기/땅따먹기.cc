#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end());
using namespace std;
using ll=long long;

struct line {
    ll a, b;
    line(ll a, ll b) : a(a), b(b) {}
    ll f(ll x) { return a*x+b; }
};

struct StkCHT {
    vector<line> stk;
    int pv;
    StkCHT() : pv(0) {stk.clear();}
    bool chk(const line &a, const line &b, const line &c) const { return (__int128_t)(a.b-b.b)*(c.a-b.a) >= (__int128_t)(b.b-c.b)*(b.a-a.a); }
    bool chk(const line &a, const line &b, const ll x) const { return (__int128_t)(b.a-a.a)*x <= a.b-b.b; }
    void add(line l) {
        while(stk.size() >= pv+2 && chk(stk[stk.size()-2],stk.back(),l)) stk.pop_back();
        stk.push_back(l);
    }
    ll qry(ll x) {
        while(pv+1 < stk.size() && chk(stk[pv],stk[pv+1],x)) pv++;
        return stk[pv].f(x);
    }
} cht;

ll N, D[50505];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<pair<ll,ll>> t(N), v;
    for(auto &[w,h]:t) cin >> w >> h;
    sort(all(t),greater<>());
    ll mx=0;
    for(auto [w,h]:t) {
        if(h > mx) v.push_back({w,h});
        mx = max(mx, h);
    }
    reverse(all(v));
    N = v.size();

    cht.add(line(v[0].second, 0));
    for(int i=1;i<=N;i++) {
        D[i] = cht.qry(v[i-1].first);
        if(i<N) cht.add(line(v[i].second, D[i]));
    }
    cout << D[N];
    return 0;
}