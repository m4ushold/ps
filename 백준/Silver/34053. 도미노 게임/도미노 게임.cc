#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, A[1010][1010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    ll zc=0, cnt=0, mn=1e9;
    
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        int x; cin >> x;
        if(x) cnt+=x, mn=min<ll>(mn, x);
        else zc++;
    }
    if(zc) cout << cnt;
    else cout << cnt-mn;
    return 0;
}