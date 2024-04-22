#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int INF=1e9;

template <typename node_t>
struct SegTree {
    const static int sz=1<<19;
    node_t T[sz<<1];
    void init() { for(int i=0;i<sz*2;i++) T[i]=INF; }
    node_t m(node_t a, node_t b) { return min(a,b); }
    void build() { for(int i=sz-1;i>=1;i--) T[i]=m(T[i*2],T[i*2+1]); }
    void upd(int i, node_t x) {
        i|=sz, T[i]=x;
        while(i>>=1) T[i]=m(T[i*2],T[i*2+1]);
    }
    node_t qry(int l, int r) {
        node_t res=INF;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=m(res,T[l++]);
            if(~r&1) res=m(res,T[r--]);
        }
        return res;
    }
};
SegTree<ll> seg;

tuple<int,int,int> stu[505050];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1,t;i<=n;i++) {
        cin >> t;
        auto &[a,b,c]=stu[t];
        a=i;
    }
    for(int i=1,t;i<=n;i++) {
        cin >> t;
        auto &[a,b,c]=stu[t];
        b=i;
    }
    for(int i=1,t;i<=n;i++) {
        cin >> t;
        auto &[a,b,c]=stu[t];
        c=i;
    }
    sort(stu+1,stu+n+1);

    int cnt=0;
    seg.init();
    for(int i=1;i<=n;i++) {
        auto [a,b,c]=stu[i];
        int d=seg.qry(1,b-1);
        if(d==INF || d>c) cnt++;
        seg.upd(b,c);
    }
    cout << cnt;
    return 0;
}