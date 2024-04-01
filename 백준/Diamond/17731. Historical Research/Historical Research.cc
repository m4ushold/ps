#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, B, K, Q, A[101010];
ll R[101010], res;
vector<int> v;

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
        while(v>>=1) T[v]=max(T[v*2],T[v*2+1]);
    }
} seg;


void add(int i) { seg.update(i,v[i-1]); }

void sub(int i) { seg.update(i,-v[i-1]); }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q; B=sqrt(N);
    v.resize(N);
    for(int i=1;i<=N;i++) cin >> A[i], v[i-1]=A[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;

    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=seg.T[1];

	for(int i=1; i<Q; i++){
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(s < qry[i].s) sub(A[s++]);
		while(e > qry[i].e) sub(A[e--]);
		R[qry[i].i] = seg.T[1];
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}