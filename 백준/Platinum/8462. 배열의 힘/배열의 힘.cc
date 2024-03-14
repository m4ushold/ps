#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, B, Q, A[101010], R[101010], C[1010101], res;
struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
        return s < a.s; 
    }
};
vector<Qry> qry;

void sub(int v) {
    res-=C[v]*C[v]*v;
    C[v]--;
    res+=C[v]*C[v]*v;
}

void add(int v) {
    res-=C[v]*C[v]*v;
    C[v]++;
    res+=C[v]*C[v]*v;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q; B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    ll s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=res;

	for(int i=1; i<Q; i++){
		while(s < qry[i].s) sub(A[s++]);
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(e > qry[i].e) sub(A[e--]);
		R[qry[i].i] = res;
	}
	for(int i=0; i<Q; i++) cout << R[i] << "\n";
    return 0;
}