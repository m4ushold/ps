#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[2020][2020];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b; cin >> a >> b;
    for(int i=a;i<=b;i++) for(int j=1,g;j<=i;j++) g=gcd(i,j), A[i/g][j/g]=1;

    int dap=0;
    for(int i=0;i<2020;i++) for(int j=0;j<2020;j++) if(A[i][j]) dap++;
    cout << dap;
    return 0;
}