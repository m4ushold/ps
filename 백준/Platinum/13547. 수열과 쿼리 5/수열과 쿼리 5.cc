#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, B, A[101010], R[101010], C[1010101];
struct Qry {
    int idx, s, e;
    bool operator<(Qry &a) { return s/B == a.s/B ? e < a.e : s/B < a.s/B; }
};

vector<Qry> qry;

int sub(int v) {
    C[v]--;
    return !C[v];
}

int add(int v) {
    C[v]++;
    return C[v]==1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N; B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i];
    int q; cin >> q;
    for(int i=0,s,e;i<q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    int s=qry[0].s, e=qry[0].e, res=0;
    for(int i=s;i<=e;i++) res+=!C[A[i]], C[A[i]]++;
	R[qry[0].idx]=res;
	for(int i=1; i<q; i++){
		while(s < qry[i].s) res -= sub(A[s++]);
		while(s > qry[i].s) res += add(A[--s]);
		while(e < qry[i].e) res += add(A[++e]);
		while(e > qry[i].e) res -= sub(A[e--]);
		R[qry[i].idx] = res;
	}
	for(int i=0; i<q; i++) cout << R[i] << "\n";

    return 0;
}