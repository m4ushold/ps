#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, A[101010], B[101010];

ll f() {
    ll sum=0;
    for(int i=2;i<=N;i++) sum+=A[i];
    for(int i=N;i;i--) B[i]=A[i]+B[i+1];
    ll mx=LONG_LONG_MIN;
    for(int i=2;i<N;i++) {
        mx=max(mx, B[i+1]-A[i]);
    }
    return sum+mx;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    ll mx=f();
    reverse(A+1, A+N+1);
    ll sum = accumulate(A, A+N+1, 0LL) + *max_element(A,A+N+1)-A[1]-A[N];
    cout << max({mx,f(),sum});
    return 0;
}