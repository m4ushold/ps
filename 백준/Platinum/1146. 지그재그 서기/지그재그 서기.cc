#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e6;
int N, D[101][101];

int f(int l, int r) {
    if(D[l][r] != -1) return D[l][r];
    int res=0;
    for(int i=0;i<l;i++) res = (res + f(r+i, l-i-1)) % mod;
    return D[l][r] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    if(N==1) return cout << 1, 0;
    memset(D, -1, sizeof(D));
    D[0][0]=1;
    
    int ans=0;
    for(int i=0;i<N;i++) {
        ans = (ans + f(i,N-i-1) * 2 % mod) % mod;
    }
    cout << ans;
    return 0;
}