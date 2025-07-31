#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

ll fac(ll n) {
    ll res=1;
    for(int i=2;i<=n;i++) res*=i;
    return res;
}

ll N, K, A[22], L[22], T[1010], D[1<<15][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<string> v(N);
    for(auto &i:v) cin >> i;
    cin >> K;
    int i=0;
    for(auto s:v) {
        int tmp=0;
        for(char c:s) tmp=(tmp*10+c-48)%K;
        A[i]=tmp;
        L[i]=s.size();
        i++;
    }
    T[0]=1;
    for(int i=1;i<1010;i++) T[i]=T[i-1]*10%K;

    D[0][0]=1;
    for(int i=0;i<1<<N;i++) {
        for(int j=0;j<N;j++) if(~(i>>j) & 1) {
            for(int k=0;k<K;k++) {
                int n = (k * T[L[j]] + A[j])%K;
                D[i|(1<<j)][n] += D[i][k];
            }
        }
    }
    ll f = fac(N), d = D[(1<<N)-1][0], g = gcd(f,d);
    cout << d/g << '/' << f/g;
    return 0;
}