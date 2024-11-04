#include <bits/stdc++.h>
using namespace std;

int A[505][505];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    while(n--) {
        int x,y,xx,yy; cin >> x >> y >> xx >> yy;
        for(int i=x;i<xx;i++) for(int j=y;j<yy;j++) A[i][j]=1;
    }
    int ans=0;
    for(int i=0;i<505;i++) ans+=accumulate(A[i], A[i]+505, 0);
    cout << ans;
    return 0;
}