#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, Q, A[101010], C[101010];

int qry(ll x) {
    if(N==1) return 0;
    if(!x) return C[0]>0;
    for(ll i=1;i*i<=x && i<=10'000;i++) if(x%i==0 && x/i<=10'000 && C[i] && C[x/i]) {
        if(i^(x/i)) return 1;
        return C[i]>1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> A[i], C[A[i]]++;
    for(ll i=1,a,b;i<=Q;i++) {
        cin >> a >> b;
        if(a==1) cout << qry(b) << '\n';
        else C[A[b]]--, C[0]++, A[b]=0;
    }
    return 0;
}