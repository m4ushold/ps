#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, A[1010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=2;i<=N;i++) {
        for(int j=1;j<i;j++) A[i]=max(A[i], A[j]+A[i-j]);
    }
    cout << A[N];
    return 0;
}