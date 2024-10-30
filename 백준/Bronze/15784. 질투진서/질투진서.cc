#include <bits/stdc++.h>
using namespace std;

int A[1010][1010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,a,b; cin >> n >> a >> b;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> A[i][j];
    int c=A[a][b];
    for(int i=1;i<=n;i++) {
        if(A[a][i] > c || A[i][b] > c) return cout << "ANGRY", 0;
    }
    cout << "HAPPY";
    return 0;
}