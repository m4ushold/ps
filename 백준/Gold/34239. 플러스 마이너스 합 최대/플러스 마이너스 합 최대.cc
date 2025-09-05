#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
ll N, A[202020], S[2], M[2], MM[2];
void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
 
    ll mx=LLONG_MIN/2, sum=0, o=1e18, e=0;
    for(int i=1;i<=N;i++) {
        sum += A[i] * (i&1?-1:1);
        mx=max({sum-o, e-sum, mx});
        
        if(i&1) o=min(o,sum);
        else e=max(e,sum);
    }
    cout << mx;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}