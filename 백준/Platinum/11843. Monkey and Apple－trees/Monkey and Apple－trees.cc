#include "bits/stdc++.h"
using namespace std;

struct Node {
    int l,r,v,lz;
    Node() {l=r=-1, v=lz=0;}
};

const int sz = 1e9;
struct DynamicSeg {
    vector<Node> T;
    DynamicSeg() {
        T.push_back(Node());
    }
    void prop(int i, int s, int e) {
        if(i==-1 || !T[i].lz) return;
        T[i].v = (e-s+1);
        if(s != e) {
            if(T[i].l==-1) T[i].l=T.size(), T.push_back(Node());
            if(T[i].r==-1) T[i].r=T.size(), T.push_back(Node());
            T[T[i].l].lz = 1, T[T[i].r].lz = 1;
        }
        T[i].lz=0;
    }
    void update(int l, int r, int x, int i=0, int s=1, int e=sz) {
        prop(i,s,e);
        if(i==-1 || r < s || e < l) return;
        else if(l <= s && e <= r) {T[i].lz += x, prop(i,s,e); return;}
        int m = s+e>>1;
        if(T[i].l==-1) T[i].l=T.size(), T.push_back(Node());
        if(T[i].r==-1) T[i].r=T.size(), T.push_back(Node());
        update(l,r,x,T[i].l,s,m), update(l,r,x,T[i].r,m+1,e);
        T[i].v = T[T[i].l].v + T[T[i].r].v;
    }
    int query(int l, int r, int i=0, int s=1, int e=sz) {
        prop(i,s,e);
        if(i==-1 || r < s || e < l) return 0;
        else if(l <= s && e <= r) return T[i].v;
        int m = s+e>>1;
        return query(l,r,T[i].l,s,m) + query(l,r,T[i].r,m+1,e);
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0,d,x,y,c=0;i<n;i++) {
        cin >> d >> x >> y;
        if(d==1) cout << (c=seg.query(x+c,y+c)) << '\n';
        else seg.update(x+c,y+c,1);
    }
    return 0;
}