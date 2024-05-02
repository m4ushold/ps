#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, K, A[20202], D[20202];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) {
        D[i]=LONG_LONG_MAX;
        ll mn=A[i],mx=A[i];
        for(int j=i;j>max(i-M,0LL);j--) {
            mn=min(mn,A[j]), mx=max(mx,A[j]);
            D[i]=min(D[i],D[j-1]+K+(i-j+1)*(mx-mn));
        }
    }
    cout << D[N];
    return 0;
}