#include <bits/stdc++.h>
using namespace std;

int N, B;
char A[101][101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j];
    cin >> B;
    if(B==1) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) cout << A[i][j];
            cout << '\n';
        }
    } else if(B==2) {
        for(int i=1;i<=N;i++) {
            for(int j=N;j;j--) cout << A[i][j];
            cout << '\n';
        }
    } else {
        for(int i=N;i;i--) {
            for(int j=1;j<=N;j++) cout << A[i][j];
            cout << '\n';
        }
    }
    return 0;
}