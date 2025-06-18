#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll T, N, M, A[101], B[101], C[101], D[101];

ll f1(ll m) {
    ll res=0;
    for(int i=1;i<=N;i++) {
        if(A[i] > m) continue;
        res += max(0LL, (m-A[i])/B[i]) + 1;
    }
    return res;
}

ll f2(ll m) {
    ll res=0;
    for(int i=1;i<=M;i++) {
        if(C[i] > m) continue;
        res += max(0LL, (m-C[i])/D[i]) + 1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T >> N;
    for(int i=1;i<=N;i++) cin >> A[i] >> B[i];
    cin >> M;
    for(int i=1;i<=M;i++) cin >> C[i] >> D[i];

    ll l=0, r=T;
    while(l<r) {
        ll m=l+r+1>>1;
        if(min(f1(m-1)+1, f1(m)) <= f2(T-m)) l=m;
        else r=m-1;
    }
    cout << l;
    return 0;
}