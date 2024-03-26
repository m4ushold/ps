#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, DP[202]={1,1,1,1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=4;i<=N;i++) DP[i]=DP[i-1]+DP[i-3];
    cout << DP[N];
    return 0;
}