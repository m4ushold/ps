#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, A[101010], D[101010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    D[1]=A[1];
    for(int i=2;i<=N;i++) D[i] = A[i] + min(D[i-1],D[i-2]);
    cout << min(D[N],D[N-1]);
    return 0;
}