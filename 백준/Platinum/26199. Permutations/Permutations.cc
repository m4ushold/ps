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
    int kth(int k) {
        int i=1;
        while(i<sz) {
            if(k<=T[i*2]) i<<=1;
            else k-=T[i*2], i=i<<1|1;
        }
        return i^sz;
    }
};

int op(int a, int b) {return a+b;}
int e() {return 0;}

void dfs(int x, vector<int> &v, vector<int> &f, vector<int> &res) {
    res.push_back(x), f[x]=1;
    if(f[v[x]]==0) dfs(v[x],v,f,res);
}

void sol(int tc) {
    int n; cin >> n;
    vector<int> v(n);
    segtree<int,op,e> seg(n);
    for(int i=0;i<n;i++) seg.set(i,1);
    for(int i=0,x;i<n;i++) {
        cin >> x;
        int j = seg.kth(x+1);
        v[j] = i;
        seg.set(j,0);
    }

    vector<int> f(n);
    for(int i=0;i<n;i++) if(!f[i]) {
        vector<int> res;
        dfs(i,v,f,res);
        cout << "(";
        for(int j=0;j<res.size();j++) {
            cout << res[j]+1 << (j==res.size()-1 ? ')':' ');
        }
        cout << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}