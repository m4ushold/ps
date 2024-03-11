# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;

int N, B, Q, A[1010101], R[1010101], C[1010101], res;

struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e<a.e : e>a.e;
        return s < a.s;
    }
};

void sub(int v) {
    C[v]--;
    if(!C[v]) res--;
}

void add(int v) {
    C[v]++;
    if(C[v]==1) res++;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N; B=sqrt(N);
    vector<int> v(N);
    for(int i=1;i<=N;i++) cin >> A[i], v[i-1]=A[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;

    cin >> Q;
    vector<Qry> qry(Q);
    for(int i=0;i<Q;i++) cin >> qry[i].s >> qry[i].e, qry[i].i=i;
    sort(qry.begin(),qry.end());

    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=res;

	for(int i=1; i<Q; i++){
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(s < qry[i].s) sub(A[s++]);
		while(e > qry[i].e) sub(A[e--]);
		R[qry[i].i] = res;
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}