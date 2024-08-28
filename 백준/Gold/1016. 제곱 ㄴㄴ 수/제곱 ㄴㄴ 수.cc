#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int S[1010101]={1,1}, A[1010101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll mn, mx; cin >> mn >> mx;
    for(ll i=2;i*i<=1'000'000'000'000LL;i++) if(!S[i]) for(int j=2*i;j<=1'000'000;j+=i) S[j]=1;
    for(ll p=2;p<=1'000'000;p++) if(!S[p]) {
        ll s=mn/p/p*p*p;
        if(s < mn) s+=p*p;
        for(ll i=s;i<=mx;i+=p*p) A[i-mn]=1;
    }

    int cnt=0;
    for(ll i=mn;i<=mx;i++) if(!A[i-mn]) cnt++;
    cout << cnt;
    return 0;
}