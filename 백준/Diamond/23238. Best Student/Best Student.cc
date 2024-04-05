#include <bits/stdc++.h>
using namespace std;
using ll=long long;

// C is cnt of element, D is cnt of cnt
int N, B, Q, A[101010], C[101010], D[101010], S[101010][404], MX;
ll R[101010], res;

struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
        return s < a.s; 
    }
};

void add(int v) {
    if(C[v]==MX && !D[C[v]+1]) MX++;
    D[C[v]+1]++, D[C[v]]--, C[v]++;

    S[C[v]][v/B]++, S[C[v]-1][v/B]--;
}

void sub(int v) {
    if(C[v]==MX && D[C[v]]==1) MX--;
    D[C[v]-1]++, D[C[v]]--, C[v]--;

    S[C[v]][v/B]++, S[C[v]+1][v/B]--;
}

int calc() {
    for(int i=N/B;i>=0;i--) if(S[MX][i]) {
        for(int j=B-1;j>=0;j--) if(C[i*B+j]==MX) return i*B+j;
    }
    return 0;
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
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=v[calc()-1];

	for(int i=1; i<Q; i++){
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(s < qry[i].s) sub(A[s++]);
		while(e > qry[i].e) sub(A[e--]);
		R[qry[i].i]=v[calc()-1];
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}