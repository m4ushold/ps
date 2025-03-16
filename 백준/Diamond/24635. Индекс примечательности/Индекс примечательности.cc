#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll P, N, B, K, Q, A[101010], R[101010], ANS, T[101010], F[101010], C[202020];
string S;

struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
        return s < a.s; 
    }
};

void add(int i) {
    ANS += C[i];
    C[i]++;
}

void sub(int i) {
    C[i]--;
    ANS -= C[i];
}

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%P;
        a=a*a%P, n/=2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> P >> S >> Q, N=S.size(), B=sqrt(N);
    if(P == 2 || P == 5) {
        for(int i=1;i<=N;i++) {
            T[i] = T[i-1], F[i] = F[i-1];
            if((S[i-1]-48)%P == 0) T[i] += i, F[i]++;
        }
        for(int i=1,s,e;i<=Q;i++) {
            cin >> s >> e;
            cout << T[e]-T[s-1] - (F[e]-F[s-1])*(s-1) << '\n';
        }
        return 0;
    }
    vector<int> v;
    for(ll i=N,b=1;i;i--) {
        A[i] = A[i+1] + (S[i-1]-48)*b%P, A[i]%=P, b=b*10%P;
        v.push_back(A[i]);
    }
    v.push_back(0);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=N;i++) {
        A[i] = lower_bound(v.begin(),v.end(),A[i])-v.begin();
    }
    
    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    int s=qry[0].s, e=qry[0].e;
    for(int i=s;i<=e;i++) add(A[i]);
	R[qry[0].i]=ANS + C[A[e+1]];

	for(int i=1; i<Q; i++){
		while(s > qry[i].s) add(A[--s]);
		while(e < qry[i].e) add(A[++e]);
		while(s < qry[i].s) sub(A[s++]);
		while(e > qry[i].e) sub(A[e--]);
		R[qry[i].i]=ANS + C[A[qry[i].e+1]];
	}
	for(int i=0;i<Q;i++) cout << R[i] << "\n";
    return 0;
}