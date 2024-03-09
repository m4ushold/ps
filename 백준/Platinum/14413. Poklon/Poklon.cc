#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, B, Q, A[505050], R[505050], C[505050], res;
struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { return s/B == a.s/B ? e < a.e : s/B < a.s/B; }
};

vector<Qry> qry;

void sub(int v) {
    C[v]--;
    if(C[v]==1) res--;
    if(C[v]==2) res++;
}

void add(int v) {
    C[v]++;
    if(C[v]==2) res++;
    if(C[v]==3) res--;
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
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}