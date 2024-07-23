#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int P[11];

void sol(int id) {
    memset(P, -1, sizeof(P));
    int n; cin >> n;
    int cnt=0;
    for(int i=0,j,p;i<n;i++) {
        cin >> j >> p;
        if(P[j]>=0 && P[j]!=p) cnt++;
        P[j]=p;
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}