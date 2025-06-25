#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<18;
ll N, L, A[sz], S[sz], B[sz], W[sz];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> L;
    for(int i=1;i<=N;i++) cin >> A[i], S[i] = S[i-1] + A[i];
    ll l=N, r=N, sum=A[N];
    B[N] = 1, W[N] = A[N];
    while(--l) {
        sum += A[l];
        while(sum > L) sum -=A[r], r--;
        B[l] = B[r+1]+1;
        W[l] = r==N ? S[N] - S[l-1] : W[r+1];
    }
    for(int i=1;i<=N;i++) cout << B[i] << ' ' << W[i] << '\n';
    return 0;
}