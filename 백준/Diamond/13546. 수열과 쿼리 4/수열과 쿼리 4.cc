#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, B, K, Q, A[101010], R[101010], res;
list<int> D[101010];
struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e<a.e : e>a.e;
        return s < a.s; 
    }
};

int C[101010], S[404];

int mx() {
    int r = N/B;
    for(int i=r;i>=0;i--) if(S[i]) {
        for(int j=B-1;j>=0;j--) if(C[i*B+j]) return i*B+j;
    }
    return 0;
}

void add(int i, int f) {
    int v=A[i], a;
    if(!D[v].empty()) a=D[v].back()-D[v].front(), C[a]--, S[a/B]--;

    f ? D[v].push_back(i) : D[v].push_front(i);
    a=D[v].back()-D[v].front(), C[a]++, S[a/B]++;
}

void sub(int i, int f) {
    int v=A[i], a;
    a=D[v].back()-D[v].front(), C[a]--, S[a/B]--;

    f ? D[v].pop_back() : D[v].pop_front();
    if(!D[v].empty()) a=D[v].back()-D[v].front(), C[a]++, S[a/B]++;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K, B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i];
    cin >> Q;
    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    ll s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(i,1);
	R[qry[0].i]=mx();

	for(int i=1; i<Q; i++){
		while(s > qry[i].s) add(--s,0);
		while(e < qry[i].e) add(++e,1);
		while(s < qry[i].s) sub(s++,0);
		while(e > qry[i].e) sub(e--,1);
		R[qry[i].i] = mx();
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}