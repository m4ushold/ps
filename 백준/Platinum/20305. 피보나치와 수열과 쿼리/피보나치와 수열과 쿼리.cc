#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int MOD=1e9+7;

ll F[1010101]={0,1}, A[1010101];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for(int i=2;i<=n+1;i++) F[i]=(F[i-2]+F[i-1])%MOD;
    for(int i=0,l,r;i<q;i++) {
        cin >> l >> r;
        A[l]=(A[l]+1)%MOD;
        A[r+1]=(A[r+1]-F[r-l+2]+MOD)%MOD;
        A[r+2]=(A[r+2]-F[r-l+1]+MOD)%MOD;
    }
    for(int i=2;i<=n;i++) A[i]=((A[i-2]+A[i-1])%MOD+A[i])%MOD;
    for(int i=1;i<=n;i++) cout << A[i] << ' ';
    return 0;
}