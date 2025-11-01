#include <bits/stdc++.h>
using namespace std;
using ll=long long;

pair<vector<int>,vector<int>> sfx(const string& s) {
    int n=s.size();
    vector<int> sa(n), pos(n), tmp(n);
    for(int i=0;i<n;i++) sa[i]=i, pos[i]=s[i];
    for(int k=1;;k*=2) {
        auto cmp = [&](int a, int b) {
            if(pos[a]!=pos[b]) return pos[a]<pos[b];
            if(a+k<n && b+k<n) return pos[a+k]<pos[b+k];
            return a>b;
        };
        sort(sa.begin(),sa.end(),cmp);
        for(int i=1;i<n;i++) tmp[i]=tmp[i-1]+cmp(sa[i-1],sa[i]);
        for(int i=0;i<n;i++) pos[sa[i]]=tmp[i];
        if(tmp.back()+1==n) break;
    }

    vector<int> lcp(n);
    for(int i=0,j=0;i<n;i++,j=max(j-1,0)) {
        if(pos[i]==0) continue;
        while(sa[pos[i]-1]+j < n && sa[pos[i]]+j < n && s[sa[pos[i]-1]+j] == s[sa[pos[i]]+j]) j++;
        lcp[pos[i]]=j;
    }
    return {sa,lcp};
}

template<class S, S (*op)(S, S), S (*e)()>
struct SegTree {
    int n, sz;
    vector<S> T;
    SegTree(int n): n(n) {
        sz=1;
        while(sz<n) sz<<=1;
        T.assign(2*sz, e());
    }
    void upd(int i, S x) {
        T[i|=sz] = x;
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

ll op(ll a, ll b) {return min(a,b);}
ll e() {return 1e9;}

void sol(int tc) {
    string s; cin >> s;
    if(s == "*") exit(0);
    
    int n = s.size(), q; cin >> q;
    SegTree<ll,op,e> seg(n);
    auto [sa,lcp] = sfx(s);
    vector<int> ridx(n);
    for(int i=0;i<n;i++) seg.upd(i, lcp[i]), ridx[sa[i]]=i;
    for(int i=0,l,r;i<q;i++) {
        cin >> l >> r;
        l=ridx[l], r=ridx[r];
        if(l>r) swap(l,r);
        cout << seg.qry(l+1,r) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i) sol(i);
    return 0;
}