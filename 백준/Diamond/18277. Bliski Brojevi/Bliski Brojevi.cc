#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using node_t=tuple<ll,ll,ll>; // ans, mn, mx

const int INF=1e9;
int N, B, Q, A[30303];
ll R[30303], res;

struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
        return s < a.s; 
    }
};

struct SegTree {
    const static int sz=1<<17;
    node_t T[sz<<1];
    void init() { for(int i=0;i<sz*2;i++) T[i]={INF,INF,0}; }
    node_t m(node_t x, node_t y) {
        auto [a,b,c]=x;
        auto [d,e,f]=y;
        if(x == make_tuple(INF,INF,0)) return y;
        if(y == make_tuple(INF,INF,0)) return x;

        return {min({a,d,e-c}),min(b,e),max(c,f)};
    }
    void update(int v, int x) {
        v|=sz;
        T[v] = x>0 ? make_tuple(INF,x,x) : make_tuple(INF,INF,0);
        while(v>>=1) T[v]=m(T[v*2],T[v*2+1]);
    }
} seg;

void add(int i) {
    seg.update(i,i);
}

void sub(int i) {
    seg.update(i,-i);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q, B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i];
    
    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());
    seg.init();

    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=get<0>(seg.T[1]);
    auto [a,b,c]=seg.T[1];

	for(int i=1; i<Q; i++){
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(s < qry[i].s) sub(A[s++]);
		while(e > qry[i].e) sub(A[e--]);
		R[qry[i].i]=get<0>(seg.T[1]);
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}