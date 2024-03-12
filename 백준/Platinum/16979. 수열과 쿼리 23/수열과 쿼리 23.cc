#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, B, K, Q, A[101010];
ll R[101010], res;

struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
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
        ll ret=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) ret+=T[l++];
            if(~r&1) ret+=T[r--];
        }
        return ret;
    }
} seg;

void add(int v, int f) {
    res += f ? seg.query(v+1,100'000) : seg.query(0,v-1);
    seg.update(v,1);
}

void sub(int v, int f) {
    res -= f ? seg.query(v+1,100'000) : seg.query(0,v-1);
    seg.update(v,-1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q; B=sqrt(N);
    vector<int> v(N);
    for(int i=1;i<=N;i++) cin >> A[i], v[i-1]=A[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;

    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i],1);
	R[qry[0].i]=res;
    
	for(int i=1; i<Q; i++) {
		while(s > qry[i].s) add(A[--s],0);
		while(e < qry[i].e) add(A[++e],1);
		while(s < qry[i].s) sub(A[s++],0);
		while(e > qry[i].e) sub(A[e--],1);
		R[qry[i].i] = res;
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}