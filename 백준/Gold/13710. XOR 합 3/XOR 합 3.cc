#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, A[101010][30];

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) {
        int x; cin >> x;
        for(int j=0;j<30;j++) A[i][j]=(x>>j)&1, A[i][j]^=A[i-1][j];
    }

    ll ans=0;
    for(int b=0;b<30;b++) {
        ll z=1;
        for(int i=1;i<=N;i++) {
            ans += (A[i][b] ? z : i-z) * (1LL<<b);
            z+=!A[i][b];
        }
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}