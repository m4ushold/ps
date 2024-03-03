#include <bits/stdc++.h>
using namespace std;

int N, T[22], P[22], D[22];

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> T[i] >> P[i];
    for(int i=1;i<=N+1;i++) for(int j=1;j<=i;j++) if(j+T[j]<=i) D[i]=max(D[i], D[j]+P[j]);
    cout << *max_element(D,D+N+2);
    return 0;
}