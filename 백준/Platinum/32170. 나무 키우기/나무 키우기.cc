#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int mod = 1e9+7;

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%mod;
        a=a*a%mod, n>>=1;
    }
    return res;
}

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
    int get(int i) {
        return T[i|sz];
    }
    S qry(int l, int r) {
        S L=e(), R=e();
        for(l|=sz,r|=sz;l<=r;l>>=1,r>>=1) {
            if(l&1) L=op(L,T[l++]);
            if(~r&1) R=op(T[r--],R);
        }
        return op(L,R);
    }

    int kth(int k) {
        int i=1;
        while(i<sz) {
            if(T[i*2] >= k) i<<=1;
            else k-=T[i*2], i=i<<1|1;
        }
        return i^sz;
    }
};

int op(int a, int b) {return a+b;}
int e() {return 0;}

void sol(int tc) {
    int n; cin >> n;
    priority_queue<int,vector<int>,greater<>> pq;
    segtree<int,op,e> seg(303030);
    int mx=0;
    for(int i=0,a;i<n;i++) {
        cin >> a;
        pq.push(a);
        seg.set(a,seg.get(a)+1);
        mx=max(mx,a);
    }

    map<int,vector<pll>> qry;
    int q; cin >> q;
    vector<int> r(q);
    for(int i=0;i<q;i++) {
        int x,k; cin >> x >> k;
        qry[x].push_back({k,i});
    }

    int d=1;
    while(1) {
        int a = pq.top(); pq.pop();
        if(a*2 >= mx) {
            pq.push(a);
            break;
        }
        seg.set(a,seg.get(a)-1);
        seg.set(a*2,seg.get(a*2)+1);
        pq.push(a*2);

        for(auto [k,j]:qry[d]) r[j] = seg.kth(k);

        ++d;
    }
    vector<int> aa;
    while(pq.size()) aa.push_back(pq.top()), pq.pop();

    --d;
    for(auto [dd,v]:qry) if(dd>d) {
        ll b = pw(2,(dd-d)/n);
        for(auto [k,i]:v) {
            r[i] = 1;
            int t = (dd-d)%n + k - 1;
            if(t >= n) t-=n, r[i] = 2;
            r[i] = r[i] * aa[t] % mod * b % mod;
        }
    }

    for(int i:r) cout << i << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}