#include <bits/stdc++.h>
using namespace std;

int A[2][10];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    for(int i=0,s,y;i<n;i++) cin >> s >> y, ++A[s][y];
    int res=0;
    for(int i=0;i<2;i++) for(int j=1;j<=6;j++) res+=A[i][j]/k + (A[i][j]%k!=0);
    cout << res;
    return 0;
}