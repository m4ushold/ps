#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, B, A[101010], R[101010], C[101010], D[101010], MX;
struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
        return s < a.s; 
    }
};

vector<Qry> qry;

void sub(int v) {
    if(C[v]==MX && D[C[v]]==1) MX--;
    D[C[v]]--, D[C[v]-1]++, C[v]--;
}

void add(int v) {
    if(C[v]==MX && !D[C[v]+1]) MX++;
    D[C[v]+1]++, D[C[v]]--, C[v]++;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N; B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i];
    int q; cin >> q;
    for(int i=0,s,e;i<q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    D[0]=N;
    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=MX;
	for(int i=1; i<q; i++){
		while(s < qry[i].s) sub(A[s++]);
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(e > qry[i].e) sub(A[e--]);
		R[qry[i].i] = MX;
	}
	for(int i=0; i<q; i++) cout << R[i] << "\n";
    return 0;
}