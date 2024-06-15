#include <bits/stdc++.h>
using namespace std;

char A[404][404];

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    memset(A,'.',sizeof A);
    int n; cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) A[i][j]='G';
    for(int i=n;i<2*n;i++) for(int j=n;j<2*n;j++) A[i][j]='I';
    for(int i=n;i<n+n;i++) for(int j=3*n;j<4*n;j++) A[i][j]='T';
    for(int i=2*n;i<3*n;i++) for(int j=2*n;j<3*n;j++) A[i][j]='S';
    for(int i=0;i<n*3;i++) {
        for(int j=0;j<n*4;j++) cout << A[i][j];
        cout << '\n';
    }

    return 0;
}