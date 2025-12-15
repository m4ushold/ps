#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 1<<17;
struct SegTree {
    array<int,3> T[sz<<1];
    int L[sz<<1];
    void init(int n, int node=1, int s=0, int e=sz-1) {
        L[node] = 0;
        if(s == e) {
            if(s < n) T[node] = {1, 0, 0}; 
            else T[node] = {0, 0, 0};
            return;
        }

        int m = s+e>>1;
        init(n, node*2, s, m), init(n, node*2+1, m+1, e);
        T[node] = op(T[node*2], T[node*2+1]);
    }
    void push(int node, int s, int e) {
        if(L[node]==0) return;
        L[node] %= 3;
        array<int,3> t;
        for(int i=0;i<3;i++) t[(i+L[node])%3] = T[node][i];
        T[node] = t;
        if(s!=e) L[node*2]+=L[node], L[node*2+1]+=L[node];
        L[node]=0;
    }
    array<int,3> op(array<int,3> a, array<int,3> b) {
        return array<int,3>{a[0]+b[0], a[1]+b[1], a[2]+b[2]};
    }
    void upd(int l, int r, int v, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[node]=v, push(node,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,node*2,s,m), upd(l,r,v,node*2+1,m+1,e);
        T[node]=op(T[node*2],T[node*2+1]);
    }
    array<int,3> query(int l, int r, int node=1, int s=0, int e=sz-1) {
        push(node,s,e);
        if(r<s || e<l) return {0,0,0};
        else if(l<=s && e<=r) return T[node];
        int m=s+e>>1;
        return op(query(l,r,2*node,s,m),query(l,r,2*node+1,m+1,e));
    }
} seg;

void sol(int n, int m) {
    seg.init(n);
    for(int i=0,a,b;i<m;i++) {
        char op; cin >> op >> a >> b;
        if(op == 'M') {
            seg.upd(a-1,b-1,1);
        } else {
            auto x = seg.query(a-1,b-1);
            cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
        }
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    while(cin >> n) cin >> m, sol(n,m);
    return 0;
}