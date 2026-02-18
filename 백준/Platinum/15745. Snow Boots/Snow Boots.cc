#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

template<class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n, sz;
    vector<S> T;
    segtree(int n): n(n) {
        sz=1;
        while(sz<n) sz<<=1;
        T.assign(2*sz, e());
    }
    void set(int i, S x) {
        T[i|=sz] = x;
        while(i>>=1) T[i]=op(T[i<<1],T[i<<1|1]);
    }
    void add(int i, S x) {
        T[i|sz] = op(T[i|=sz], x);
        while(i>>=1) T[i]=op(T[i<<1],T[i<<1|1]);
    }
    S qry(int l, int r) {
        S L=e(), R=e();
        for(l|=sz,r|=sz;l<=r;l>>=1,r>>=1) {
            if(l&1) L=op(L,T[l++]);
            if(~r&1) R=op(T[r--],R);
        }
        return op(L,R);
    }
};

struct S {
  int mx, l, r, len;
};
S op(S a, S b) {
  S res;
  res.len = a.len + b.len;
  if(a.l == a.len) res.l = a.len + b.l;
  else res.l = a.l;

  if(b.r == b.len) res.r = b.len + a.r;
  else res.r = b.r;

  res.mx = max({a.mx, b.mx, a.r+b.l});
  return res;
}
S e() {return S{0,0,0,0};}

void sol(int tc) {
  int n,m; cin >> n >> m;
  map<int,vector<int>> snow;
  for(int i=0,h;i<n;i++) {
    cin >> h;
    snow[h].push_back(i);
  }

  segtree<S,op,e> seg(n);
  for(int i=0;i<n;i++) seg.set(i, S{1,1,1,1});
  vector<pair<int,int>> a;
  for(auto [h,v]:snow) {
    for(int j:v) seg.set(j,{0,0,0,1});
    a.push_back({h, seg.T[1].mx});
  }

  for(int i=0,s,d;i<m;i++) {
    cin >> s >> d;
    int j = upper_bound(all(a), pair<int,int>{s,1e9}) - a.begin() - 1;
    int dd = 1e9;
    if(j>=0) dd = a[j].second;
    cout << (dd<d) << endl;
  }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}