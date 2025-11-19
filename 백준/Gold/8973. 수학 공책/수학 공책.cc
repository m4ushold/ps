#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, A[2020], B[2020], D[2020][2020];

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> B[i];
    for(int i=1;i<=N;i++) {
        D[i][i] = A[i]*B[i];
        if(i+1<=N) D[i][i+1] = A[i]*B[i+1] + A[i+1]*B[i];
    }
    for(int d=2;d<=N;d++) {
        for(int j=1;j+d<=N;j++) {
            int x = j, y = j+d;
            D[x][y] = D[x+1][y-1] + A[x]*B[y] + A[y]*B[x];
        }
    }
    ll mx=LLONG_MIN,l=0,r=0;
    for(int i=1;i<=N;i++) for(int j=i;j<=N;j++) {
        if(D[i][j] > mx) {
            mx = D[i][j];
            l = i-1;
            r = N-j;
        }
    }
    cout << l << ' ' << r << endl << mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}