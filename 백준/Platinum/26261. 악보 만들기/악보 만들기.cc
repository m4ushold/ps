#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
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

int op(int a, int b) {return min(a,b);}
int e() {return 1e9;}

int N, X, K, A[1<<18];

void sol(int tc) {
    cin >> N >> X >> K;
    for(int i=1;i<=N;i++) cin >> A[i], A[i]=A[i-1]+!A[i];
    segtree<int,op,e> seg(N+1);
    seg.set(0,0);
    for(int i=1;i<=N;i++) {
        if(A[i]-A[max(0,i-K)] == K) {
            seg.set(i, seg.qry(max(0,i-X),i-K)+1);
        }
    }

    int ans = min(seg.qry(N,N), seg.qry(max(0,N-X), N-1)+1);
    if(ans == e()) cout << -1;
    else cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}