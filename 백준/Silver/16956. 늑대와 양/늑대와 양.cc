#include <bits/stdc++.h>
using namespace std;
using ll=long long;

char A[505][505];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];
    int f=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(A[i][j]=='S' && (A[i+1][j]=='W' || A[i][j+1]=='W')) f=1;
        if(A[i][j]=='W' && (A[i+1][j]=='S' || A[i][j+1]=='S')) f=1;
    }
    if(f) cout << 0;
    else {
        cout << "1\n";
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(A[i][j]=='.') cout << "D";
                else cout << A[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}