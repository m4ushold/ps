#include <bits/stdc++.h>
using namespace std;

int T, N, A[303];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<303;i++) A[i]=i*(i+1)*(i+2)/2+A[i-1];
    cin >> T;
    while(T--) cin >> N, cout << A[N] << '\n';
    return 0;
}