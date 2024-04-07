#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[303][303], B[303][303], C[303][303];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> A[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> B[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        for(int k=1;k<=n;k++) C[i][j]|=A[i][k]&B[k][j];
    }
    int cnt=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cnt+=C[i][j];
    cout << cnt;
    return 0;
}