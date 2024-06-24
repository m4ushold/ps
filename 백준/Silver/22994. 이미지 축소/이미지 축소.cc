#include <bits/stdc++.h>
using namespace std;

char A[1010][1010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> A[i][j];

    int r=n, c=m;
    for(int i=1,cnt=1;i<=n;i++,cnt=1) {
        for(int j=2;j<=m;j++) {
            if(A[i][j-1]==A[i][j]) cnt++;
            else c=gcd(c,cnt), cnt=1;
        }
    }

    for(int j=1,cnt=1;j<=m;j++,cnt=1) {
        for(int i=2;i<=n;i++) {
            if(A[i-1][j]==A[i][j]) cnt++;
            else r=gcd(r,cnt), cnt=1;
        }
    }

    cout << n/r << ' ' << m/c << '\n';
    for(int i=1;i<=n;i+=r) {
        for(int j=1;j<=m;j+=c) cout << A[i][j];
        cout << '\n';
    }
    return 0;
}