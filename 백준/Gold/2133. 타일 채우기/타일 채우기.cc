#include <bits/stdc++.h>
using namespace std;

int N, DP[33]={1,0,3};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=4;i<33;i++) {
        DP[i]=3*DP[i-2];
        for(int j=4;j<=i;j+=2) DP[i]+=2*DP[i-j];
    }
    cout << DP[N];
    return 0;
}