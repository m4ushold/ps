#include <bits/stdc++.h>
using namespace std;

int C[1010]={0,1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k,r=1; cin >> n >> m >> k;
    for(int i=0,a;i<m;i++) cin >> a, r=(r-1+a+n)%n+1, C[r]++;
    cout << C[k];
    return 0;
}