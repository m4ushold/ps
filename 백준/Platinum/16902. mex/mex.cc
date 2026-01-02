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
    int mex(int x=0) {
        string s = bitset<19>(x).to_string();
        int i=1, idx=0;
        while(i<sz) {
            int f = s[idx]=='1';
            if(T[i*2+f]) i=i*2+!f;
            else i=i*2+f;
            ++idx;
        }
        return i^sz;
    }
};

int op(int a, int b) {return min(a,b);}
int e() {return 0;}

void sol(int tc) {
    int n,m; cin >> n >> m;
    segtree<int,op,e> seg(1<<19);
    for(int i=0,a;i<n;i++) {
        cin >> a;
        seg.set(a,1);
    }
    int x=0;
    for(int i=0,a;i<m;i++) {
        cin >> a, x^=a;
        cout << (seg.mex(x)^x) << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}