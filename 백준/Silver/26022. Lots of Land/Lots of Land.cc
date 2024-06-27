#include <bits/stdc++.h>
using namespace std;
 
int N, M, K;
char A[101][101];
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    if(N*M%K) cout << "IMPOSSIBLE";
    else {
        int cnt=N*M/K;
        int a=gcd(N,cnt);
        cnt/=gcd(N,cnt);
        int b=gcd(cnt,M);
 
        char c='A';
        for(int i=1;i<=N;i+=a) for(int j=1;j<=M;j+=b) {
            for(int ii=i;ii<i+a;ii++) for(int jj=j;jj<j+b;jj++) A[ii][jj]=c;
            c++;
        }
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) cout << A[i][j];
            cout << '\n';
        }
    }
    return 0;
}