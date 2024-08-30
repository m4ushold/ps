#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, D[1010][1010][2], P[1010], W[1010];

ll dp(int l, int r, int f) {
    if(l==1 && r==N) return 0;
    if(D[l][r][f]!=-1) return D[l][r][f];

    ll pos = f ? P[l] : P[r], res=LONG_LONG_MAX/2;
    if(l>1) res=min(res,dp(l-1, r, 1) + abs(pos - P[l-1]) * (W[N] - W[r] + W[l-1]));
    if(r<N) res=min(res,dp(l, r+1, 0) + abs(pos - P[r+1]) * (W[N] - W[r] + W[l-1]));
    return D[l][r][f]=res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> P[i] >> W[i];
    for(int i=1;i<=N;i++) W[i]+=W[i-1];

    memset(D, -1, sizeof(D));
    cout << dp(M, M, 0) << endl;
    return 0;
}