#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, K, B=1, C=1, S[101010];

ll sft(ll n) {
    return (n*B%K + N)%K;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    while(B<=N) B*=10;
    B%=K;

    ll n = N%K;
    while(n) {
        if(S[n]) {cout << -1; return 0;}
        S[n]=1, n=sft(n), C++;
    }
    cout << C;
    return 0;
}