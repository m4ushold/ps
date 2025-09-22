#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll A[202], D[202][202];

void sol(int tc) {
    int n,b; cin >> n >> b;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    n = v.size();
    for(int i=1;i<=n;i++) A[i]=v[i-1], D[1][i] = (A[i]-A[1])*(A[i]-A[1]);
    
    for(int i=2;i<=b;i++) {
        for(int j=1;j<=n;j++) {
            D[i][j] = LLONG_MAX/4;
            for(int k=1;k<=j;k++) {
                ll t = A[j]-A[k];
                t*=t;
                D[i][j] = min(D[i][j], D[i-1][k-1] + t);
            }
            // cout << D[i][j] << ' ';
        }
        // cout << endl;
    }
    cout << D[b][n];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}