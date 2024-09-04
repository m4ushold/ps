#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, X[2323232], Y[23232325], SX[2323232], SY[2323232], R[1515], C[1515];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1,a;j<=N;j++) cin >> a, X[a]=i, Y[a]=j;
    for(int i=1;i<=N*N;i++) SX[i] = R[X[i]], SY[i] = C[Y[i]], R[X[i]]++, C[Y[i]]++;
    ll dap=0;
    for(int i=1;i<=N*N;i++) {
        dap += SX[i]*(N-SY[i]-1) + SY[i]*(N-SX[i]-1);
    }
    cout << dap/2;
    return 0;
}