#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<17;
int N, B, K, Q, A[sz], I[sz], L[sz], R[sz];
ll RR[1<<19], ans;
vector<array<int,3>> STK;

struct Qry {
    int idx, s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return e > a.e;
        return s < a.s; 
    }
};

pair<int,int> rollback() {
    auto [x,s,e] = STK.back(); STK.pop_back();

    ans += abs(I[L[x]] - I[x]) + abs(I[x] - I[R[x]]);
    ans -= x==L[x] | x==R[x] ? 0 : abs(I[L[x]] - I[R[x]]);
    
    if(x!=L[x]) R[L[x]] = x;
    if(x!=R[x]) L[R[x]] = x;
    return {s,e};
}

void sub(int x, int s, int e) {
    // calc ans
    ans -= abs(I[L[x]] - I[x]) + abs(I[R[x]] - I[x]);
    ans += x==L[x] | x==R[x] ? 0 : abs(I[L[x]] - I[R[x]]);

    // save op stk
    STK.push_back({x, s, e});

    // remove i
    R[L[x]] = x==R[x] ? L[x] : R[x];
    L[R[x]] = x==L[x] ? R[x] : L[x];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q, B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i], I[A[i]]=i;
    for(int i=1;i<=N;i++) L[i] = i-1, R[i] = i+1;
    L[1] = 1, R[N] = N;
    for(int i=1;i<N;i++) ans += abs(I[i]-I[i+1]);

    vector<Qry> qry;
    for(int i=0,s,e;i<Q;i++) cin >> s >> e, qry.push_back({i,s,e});
    sort(qry.begin(),qry.end());

    int s=1, e=N, prev=0;
    for(auto [i,l,r]:qry) {
        if(prev != l/B) while(e < N) tie(s,e) = rollback();

        while(e > r) sub(A[e], s, e), e--;
		while(s < l) sub(A[s], s, e), s++;
        
        RR[i] = ans;
        while(max(1,l/B*B) < s) tie(s,e) = rollback();
        prev = l/B;
    }

	for(int i=0;i<Q;i++) cout << RR[i] << "\n";
    return 0;
}