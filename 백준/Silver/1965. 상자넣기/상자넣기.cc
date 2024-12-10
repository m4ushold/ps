#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, A[1010], DP[1010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    ll dap=0;
    for(int i=0;i<N;i++) {
        DP[i]=1;
        for(int j=0;j<i;j++) if(A[j]<A[i]) DP[i]=max(DP[i],DP[j]+1);
        dap=max(dap,DP[i]);
    }
    cout << dap;
    return 0;
}