#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using node_t=tuple<ll,ll,ll>; // cnt, sum, e_sum

const int MOD=1e9+7;
int N, B, Q, A[101010];
ll R[202020];

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
    node_t m(node_t x, node_t y) {
        auto [a,b,c]=x;
        auto [d,e,f]=y;
        return {a+d,b+e,~a&1?(c+f)%MOD:(c+e-f+MOD)%MOD};
    }
    void update(int v, int x, int f) {
        v|=sz;
        auto &[a,b,c]=T[v];
        a=f?a+1:a-1, b+=x;
        if(f && a&1) c+=x;
        else if(!f && ~a&1) c+=x;
        b%=MOD, c%=MOD;
        while(v>>=1) T[v]=m(T[v*2],T[v*2+1]);
    }
} seg;

void add(int i, int v) {
    seg.update(i,v,1);
}

void sub(int i, int v) {
    seg.update(i,-v,0);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q; B=sqrt(N);
    vector<int> v(N);
    for(int i=0;i<N;i++) cin >> A[i], v[i]=A[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=0;i<N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin();

    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i], v[A[i]]);
	R[qry[0].i]=get<2>(seg.T[1]);

	for(int i=1; i<Q; i++){
		while(s > qry[i].s) --s, add(A[s], v[A[s]]);
		while(e < qry[i].e) ++e, add(A[e], v[A[e]]);
		while(s < qry[i].s) sub(A[s], v[A[s]]), s++;
		while(e > qry[i].e) sub(A[e], v[A[e]]), e--;
		R[qry[i].i]=get<2>(seg.T[1]);
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}