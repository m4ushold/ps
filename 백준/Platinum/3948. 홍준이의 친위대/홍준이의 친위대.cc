#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, D[101][101];

ll f(int l, int r) {
    if(D[l][r] != -1) return D[l][r];
    ll res=0;
    for(int i=0;i<l;i++) res = (res + f(r+i, l-i-1));
    return D[l][r] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(D, -1, sizeof(D));
    D[0][0]=1;

    int t; cin >> t;
    while(t--) {
        cin >> N;
        if(N==1) {
            cout << "1\n";
            continue;
        }
        
        ll ans=0;
        for(int i=0;i<N;i++) {
            ans = (ans + f(i,N-i-1) * 2);
        }
        cout << ans << '\n';
    }
    
    return 0;
}