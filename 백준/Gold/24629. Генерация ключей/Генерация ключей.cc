#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=998'244'353;
ll K, R, F[10101]={1}, D[1010][2];

ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return res;
}

ll ncr(ll n, ll r) {
    return F[n]*pw(F[r],MOD-2)%MOD*pw(F[n-r],MOD-2)%MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<10101;i++) F[i]=i*F[i-1]%MOD;
    string s, t; cin >> s >> K;
    for(char c:s) {
        if(isdigit(c)) c-='0';
        else c=c-'A'+10;
        t += bitset<4>(c).to_string();
    }

    if(t.size() < K) return cout << 0, 0;

    ll ans=0;
    for(int i=t.size()-1;i>=0;i--) {
        if(t[t.size()-i-1] == '1') {
            if(0<= K && K<=i) ans=(ans+ncr(i,K))%MOD;
            K--;
        }
    }
    if(!K) ans=(ans+1)%MOD;
    cout << ans;
    return 0;
}