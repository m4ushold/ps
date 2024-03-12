#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, B, K, Q, A[101010];
ll R[101010], res;

struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e<a.e : e>a.e;
        return s < a.s; 
    }
};

struct SegTree {
    const static int sz=1<<17;
    ll T[sz<<1];
    void update(int v, int x) {
        v|=sz, T[v]+=x;
        while(v>>=1) T[v]=T[v*2]+T[v*2+1];
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;

void add(int v) {
    res += seg.query(max(v-K,0), min(v+K, 101010));
    seg.update(v,1);
}

void sub(int v) {
    seg.update(v,-1);
    res -= seg.query(max(v-K,0), min(v+K, 101010));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K, B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i];

    cin >> Q;
    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=res;

	for(int i=1; i<Q; i++) {
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(s < qry[i].s) sub(A[s++]);
		while(e > qry[i].e) sub(A[e--]);
		R[qry[i].i] = res;
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}