#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, B, Q, A[505050], R[505050], C[505050], D[505050], MX, CNT, CNT2;
struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
        return s < a.s; 
    }
};

void sub(int v) {
    if(C[v]==MX && D[C[v]]==1) MX--;
    D[C[v]]--, D[C[v]-1]++, C[v]--;
    CNT -= !C[v];
    CNT2 -= C[v]==1;
}

void add(int v) {
    if(C[v]==MX && !D[C[v]+1]) MX++;
    D[C[v]+1]++, D[C[v]]--, C[v]++;
    CNT += C[v]==1;
    CNT2 += C[v]==2;
}

int ans(int len, int mx, int cnt, int cnt2) {
    if(cnt==2 && len==mx*2) return 0;
    if(mx*2>=len) return 1;
    return len&1 ? cnt : cnt2;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q; B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i];

    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    D[0]=N;
    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=ans(qry[0].e-qry[0].s+1, MX, CNT, CNT2);

	for(int i=1; i<Q; i++){
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(s < qry[i].s) sub(A[s++]);
		while(e > qry[i].e) sub(A[e--]);

	    R[qry[i].i]=ans(qry[i].e-qry[i].s+1, MX, CNT, CNT2);
	}
	for(int i=0; i<Q; i++) cout << R[i] << "\n";
    return 0;
}