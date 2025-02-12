#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int MOD=1e9+7, sz=1<<20;

ll pw(ll a, ll n) {
    if(n==-1) n=MOD-2;
    ll res=1;
    while(n) {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return res;
}
ll nc2(ll n) {
    return n*(n-1)/2%MOD;
}

ll N, M, A[sz], S, F[sz]={1}, I[sz]={1}, FS[sz]={1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i], S=(S+A[i])%MOD;
    
    for(int i=1;i<=N;i++) F[i]=F[i-1]*i%MOD;
    I[N] = pw(F[N], -1);
    for(int i=N-1;i>=0;i--) I[i] = I[i+1]*(i+1)%MOD;
    for(int i=1;i<=N;i++) FS[i]=(FS[i-1]+F[i])%MOD;

    char q; cin >> q;
    ll t = pw((3*nc2(N) + N)%MOD, -1), dap=0;
    if(q=='S') {
        for(ll i=1;i<=N;i++) {
            ll a,b,c,d,e;
            a = N+i-1;
            b = (i*(N-i+1)%MOD-1+MOD)%MOD*i%MOD;
            c = (i*(N-i)%MOD + i*(i-1)%MOD*(N-i+1)%MOD*pw(2,-1)%MOD)%MOD;
            d = (i*(i-1)%MOD + (i*N%MOD*(N+1)%MOD - i*i%MOD*(i+1)%MOD + MOD)%MOD*pw(2,-1)%MOD)%MOD;
            e = ((a+b+c+d)%MOD + (nc2(i-1) + nc2(N-i))%MOD * 3%MOD)%MOD;
            dap = (dap+A[i]*pw(e*t%MOD, M)%MOD)%MOD;
        }
        cout << dap*pw(S,-1)%MOD;
    } else {
        dap=nc2(N+1)+N-1;
        for(ll i=1;i<N;i++) dap = (dap + (FS[N]-FS[i]+MOD)%MOD*I[i-1]%MOD)%MOD;
        
        for(ll i=2;i<=N;i++) {
            dap = (dap + i*i%MOD*(pw(i,N-i)-1+MOD)%MOD*pw(i-1,-1)%MOD)%MOD;
            dap = (dap + i*i%MOD*(pw(i,i-1)-1+MOD)%MOD*pw(i-1,-1)%MOD)%MOD;
        }
        cout << pw(dap*t%MOD,M);
    }
    return 0;
}