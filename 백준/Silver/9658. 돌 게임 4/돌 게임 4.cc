#include <bits/stdc++.h>
using namespace std;

int N, D[1010]={0,0,1,0,1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=5;i<=N;i++) D[i]=D[i-1] && D[i-3] && D[i-4] ? 0 : 1;
    cout << (D[N] ? "SK" : "CY");
    return 0;
}