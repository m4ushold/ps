#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7, SZ=5050505;
ll N, M, A[SZ], D[SZ]={1}, F[SZ]={1}, R[SZ];

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) D[i]=D[i-1]*2%MOD, F[i]=F[i-1]*i%MOD;
    R[N] = pw(F[N], MOD-2);
    for(int i=N-1;i;i--) R[i] = R[i+1]*(i+1)%MOD;

    ll res=F[N];
    for(int i=1;i<=M;i++) {
        cin >> A[i];
        res=res*D[A[i]-1]%MOD;
        res=res*R[A[i]]%MOD;
    }
    cout << res;

    return 0;
}