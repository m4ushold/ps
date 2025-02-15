#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll M, Q, A;

ll f(ll x) {
    if(!x) return M*(M+1)/2;
    ll a=x/M, b=x%M;
    ll l=a*A+1+b*M, r=l+M-1;
    ll c=max(f(a), l);
    c<=r ? r++ : c=0;
    return (l+r)*(r-l+1)/2-c;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> Q;
    A = M*M+1;
    for(ll n;Q;Q--) {
        cin >> n;
        if(M==1) cout << 1;
        else if(M>2e9) cout << 0;
        else cout << (f(n/A) == n);
        cout << '\n';
    }
    return 0;
}