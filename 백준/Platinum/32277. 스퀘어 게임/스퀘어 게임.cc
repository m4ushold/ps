#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, B, Q, A[50505], C[50505], R[50505], D;

struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
        return s < a.s; 
    }
};

void add(ll i) {
    if(i>N) return;
	C[i]++;
	if(i>1 && C[i]==i) {
		D++, C[i]=0;
		if(i*i<=N) add(i*i);
	}
}

void sub(ll i) {
	if(i>N) return;
	if(i>1 && !C[i]) {
		if(i*i<=N) sub(i*i);
		C[i]=i, D--;
	}
	C[i]--;
}

void sol(ll tc) {
	memset(C, 0, sizeof(C));
    cin >> N, B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i];
    cin >> Q;
    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

	D=0;
    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=D;

	for(int i=1; i<Q; i++) {
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(s < qry[i].s) sub(A[s++]);
		while(e > qry[i].e) sub(A[e--]);
		R[qry[i].i]=D;
	}
	cout << "Case #" << tc << "\n";
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for(int i=1;i<=t;i++) sol(i);
    return 0;
}