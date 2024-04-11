#include <bits/stdc++.h>
using namespace std;

int N, D[101010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<101010;i++) D[i]=1e9;

    cin >> N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<317;j++) {
            if(i<j*j) break;
            D[i] = min(D[i], D[i-j*j]+1);
        }
    }
    cout << D[N];
    return 0;
}