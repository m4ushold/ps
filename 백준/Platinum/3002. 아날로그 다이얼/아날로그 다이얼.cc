#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<18;

struct Node {
    int lz, cnt[10];
    Node() : lz(0) {
        memset(cnt, 0, sizeof(cnt));
        cnt[0]=1;
    }
};

struct LazySeg {
    Node T[sz<<1];
    Node merge(Node a, Node b) {
        Node res;
        for(int i=0;i<10;i++) res.cnt[i] = a.cnt[i] + b.cnt[i];
        return res;
    }
    
    void prop(int i, int s, int e) {
        if(!T[i].lz) return;
        vector<int> t(10);
        for(int j=0;j<10;j++) t[(j+T[i].lz)%10] = T[i].cnt[j];
        for(int j=0;j<10;j++) T[i].cnt[j] = t[j];

        if(s!=e) T[i*2].lz+=T[i].lz, T[i*2+1].lz+=T[i].lz;
        T[i].lz=0;
    }
    void upd(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {T[i].lz+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        T[i]=merge(T[i*2],T[i*2+1]);
    }
    Node qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return Node();
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return merge(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        char c; cin >> c;
        seg.upd(i,i,c-'0');
    }

    for(int i=0,l,r;i<m;i++) {
        cin >> l >> r;
        int sum = 0;
        auto x = seg.qry(l,r);
        for(int j=0;j<10;j++) sum+=j*x.cnt[j];
        cout << sum << '\n';
        seg.upd(l,r,1);
    }
    return 0;
}