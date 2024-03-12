
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int P=1e9+7, SZ=1010101;
ll N, M, A[SZ], fac[SZ], inv[SZ];

ll Pow(ll a, ll b) {
    ll ret=1;
    for(;b;b>>=1,a=a*a%P) if(b&1) ret=ret*a%P;
    return ret;
}

ll comb(ll n, ll r) {
    if(n<0 || r<0) return 0;
    return fac[n]*inv[r]%P*inv[n-r]%P;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> A[i];
    
    fac[0]=1;
    for(int i=1;i<SZ;i++) fac[i]=fac[i-1]*i%P;
    inv[SZ-1]=Pow(fac[SZ-1],P-2);
    for(int i=SZ-2;~i;i--) inv[i]=inv[i+1]*(i+1)%P;

    ll res=1, s=0;
    for(int i=0;i<N;i++) {
        res = res * comb(M-s, A[i]-s) % P;
        s+=M-A[i];
    }
    cout << res;

    return 0;
}