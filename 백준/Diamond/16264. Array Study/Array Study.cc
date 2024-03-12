#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, B, Q, A[101010];
ll R;
list<int> D[202020];
struct Qry {
    int i, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e<a.e : e>a.e;
        return s < a.s; 
    }
};

int C[202020], S[505];

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
    int t; cin >> t;
    while(t--) {
        memset(A, 0, sizeof A);
        memset(S, 0, sizeof S);
        for(int i=0;i<202020;i++) D[i].clear(), C[i]=0;
        R=0;

        cin >> N, B=sqrt(N);
        A[0]=1e5;
        for(int i=1;i<=N;i++) cin >> A[i], A[i]+=A[i-1];
        cin >> Q;
        vector<Qry> qry;
        for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s-1,e});
        sort(qry.begin(),qry.end());

        ll s=qry[0].s, e=qry[0].e;
        for(int i=s;i<=e;i++) add(i,1);
        R+=mx();

        for(int i=1; i<Q; i++){
            while(s > qry[i].s) add(--s,0);
            while(e < qry[i].e) add(++e,1);
            while(s < qry[i].s) sub(s++,0);
            while(e > qry[i].e) sub(e--,1);
            R += mx();
        }
        cout << R << '\n';
    }
    return 0;
}