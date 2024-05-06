#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using node_t=ll;

int N, B, Q, A[101010], C[101010];
ll R[101010];

struct SegTree {
    const static int sz=1<<17;
    node_t T[sz<<1];
    node_t m(node_t a, node_t b) { return a+b; }
    void init() { for(int i=0;i<sz*2;i++) T[i]=0; }
    void build() { for(int i=sz-1;i>=1;i--) T[i]=m(T[i*2],T[i*2+1]); }
    void upd(int i, node_t x) {
        i|=sz, T[i]+=x;
        while(i>>=1) T[i]=m(T[i*2],T[i*2+1]);
    }
    node_t qry(int l, int r) {
        node_t res=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=m(res,T[l++]);
            if(~r&1) res=m(res,T[r--]);
        }
        return res;
    }
} sga, sgb;

struct Qry {
    int i, s, e, k;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
        return s < a.s; 
    }
};

void add(int i) {
    sga.upd(A[i],1), sgb.upd(C[i],1);
}

void sub(int i) {
    sga.upd(A[i],-1), sgb.upd(C[i],-1);
}

ll calc(int k) {
    ll ret=0, s=sqrt(k);
    for(int i=1;i<=s;i++) ret+=sga.T[sga.sz|i]*sgb.qry(1,k/i)+sgb.T[sgb.sz|i]*sga.qry(s+1,k/i);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N, B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> C[i];
    cin >> Q;
    vector<Qry> qry;
    for(int i=0,s,e,k;i<Q;i++) cin >> s >> e >> k, qry.push_back({i,s,e,k});
    sort(qry.begin(),qry.end());

    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(i);
	R[qry[0].i]=calc(qry[0].k);

	for(int i=1; i<Q; i++){
		while(s > qry[i].s) add(--s);
		while(e < qry[i].e) add(++e);
		while(s < qry[i].s) sub(s), s++;
		while(e > qry[i].e) sub(e), e--;
		R[qry[i].i]=calc(qry[i].k);
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}