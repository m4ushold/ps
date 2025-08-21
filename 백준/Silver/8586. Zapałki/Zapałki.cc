#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, A[1010101], D[2][1010101];

void sol(int tc) {
    cin >> N;
    if(N==1) {
        cout << 0;
        return;
    }
    int a=0,b=0;
    for(int i=1;i<=N;i++) cin >> A[i], b+=A[i];

    int ans=b;
    for(int i=1;i<=N;i++) {
        a+=!A[i], b-=A[i];
        ans=min(ans,a+b);
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