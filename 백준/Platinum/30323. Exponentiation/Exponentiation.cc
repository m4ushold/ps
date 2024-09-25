#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;

ll m;
map<unsigned __int128_t,unsigned __int128_t> M;

ll f(ll n) {
    if(!M.count(n/2)) f(n/2);
    if(n&1) {
        if(!M.count(n-n/2)) f(n-n/2);
        return M[n]=(M[n-n/2]*M[n/2]%m-M[1]+m)%m;
    }
    return M[n]=(M[n/2]*M[n/2]%m-2+m)%m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b; cin >> a >> b >> m;
    M[0]=2%m, M[1]=a%m;
    cout << f(b);
    return 0;
}