#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int T, N, A[1010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=1;i<=N;i++) cin >> A[i], A[i]+=A[i-1];
        int mx=INT_MIN;
        for(int i=1;i<=N;i++) for(int j=i;j<=N;j++) mx=max(mx,A[j]-A[i-1]);
        cout << mx << '\n';
    }
    return 0;
}