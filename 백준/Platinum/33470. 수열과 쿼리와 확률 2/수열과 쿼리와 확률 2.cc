#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
const int MOD=1e9+7;
ll N, M, F=1;
 
ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return res;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    
    for(int i=1,x;i<=N;i++) cin >> x, F=F*i%MOD;
    char op; cin >> op;
    if(op=='S') cout << pw(2*N%MOD*pw(N+1,MOD-2)%MOD,M);
    else cout << pw((F*pw(N+1,MOD-2)%MOD+N*pw(2,MOD-2)%MOD)%MOD, M);
    return 0;
}