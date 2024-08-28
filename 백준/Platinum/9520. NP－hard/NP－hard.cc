#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, G[1515][1515], D[1515][1515];

ll f(int s, int e){
    if(D[s][e]!=-1) return D[s][e];
    int n=max(s,e)+1;
    if(n > N) return 0;
    return D[s][e] = min(f(n,e)+G[n][s], f(s,n)+G[e][n]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> G[i][j];
    memset(D, -1, sizeof(D));
    cout << f(1,1);
    return 0;
}