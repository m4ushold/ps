#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, K, A[40404], D[40404], S[40404]={1,1};

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i*i<=40404;i++) if(!S[i]) for(int j=2*i;j<40404;j+=i) S[j]=1;
    cin >> K;
    for(int i=1;i<=K;i++) if(!S[i]) A[++N]=i;
    D[0]=1;

    for(int i=1;i<=N;i++) {
        for(int j=0;j<=K;j++) {
            if(j-A[i]>=0) D[j] = (D[j]+D[j-A[i]])%123456789LL;
        }
    }
    cout << D[K] << '\n';
    return 0;
}