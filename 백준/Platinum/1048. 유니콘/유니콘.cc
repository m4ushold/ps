#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod = 1e9+7;
ll N, M, L, A[303][303], B[303][303], T[303][303];
char C[303][303];

ll ff(int a, int b, int c, int d) {
    a = min<ll>(N,max(a,1)), c = min<ll>(N,max(c,1));
    b = min<ll>(M,max(b,1)), d = min<ll>(M,max(d,1));
    ll res = A[c][d] - A[a-1][d] - A[c][b-1] + A[a-1][b-1];
    return (res%mod+mod)%mod;
}

ll f(int i, int j) {
    ll res=ff(1,1,N,M)-ff(1,j-1,N,j+1)-ff(i-1,1,i+1,M)-ff(i-2,j-2,i+2,j+2)+ff(i-2,j-1,i+2,j+1)+ff(i-1,j-2,i+1,j+2);
    return (res%mod+mod)%mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> L;
    string s; cin >> s;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        cin >> C[i][j];
        if(C[i][j] == s[0]) B[i][j]=T[i][j]=1;
    }
    for(int k=1;k<s.size();k++) {
        char c = s[k];
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
            A[i][j] = B[i][j] = T[i][j];
            A[i][j] = (B[i][j] + (A[i-1][j]+A[i][j-1])%mod-A[i-1][j-1]+mod)%mod;
        }
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
            T[i][j] = C[i][j] == c ? f(i,j) : 0LL;
        }
    }
    
    ll res=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) res=(res+T[i][j]) % mod;
    cout << res;
    return 0;
}