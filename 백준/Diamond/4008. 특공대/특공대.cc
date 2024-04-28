#include <bits/stdc++.h>
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
    bool chk(const line &a, const line &b, const ll x) const { return (__int128_t)(b.a-a.a)*x >= a.b-b.b; }
    void add(line l) {
        while(stk.size() >= pv+2 && chk(stk[stk.size()-2],stk.back(),l)) stk.pop_back();
        stk.push_back(l);
    }
    ll qry(ll x) {
        while(pv+1 < stk.size() && chk(stk[pv],stk[pv+1],x)) pv++;
        return stk[pv].f(x);
    }
} cht;

ll N, A, B, C, X[1010101], D[1010101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> B >> C;
    for(int i=1;i<=N;i++) cin >> X[i], X[i]+=X[i-1];

    cht.add(line(0,0));
    for(int i=1;i<=N;i++) {
        D[i]=cht.qry(X[i]) + A*X[i]*X[i]+B*X[i]+C;
        cht.add(line(-2*A*X[i],A*X[i]*X[i]-B*X[i]+D[i]));
    }
    cout << D[N];
    return 0;
}