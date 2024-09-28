#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
int N, Q, A[1010101], M[1010101], C[1010101], Co[1010101], Mu[1010101];

vector<int> P;

void Sieve(int n=1'000'000) {
    Mu[1] = 1;
    for(int i=2; i<=n; i++){
        if(!C[i]) P.push_back(i), Mu[i] = -1;
        for(auto j : P){
            if(i * j > n) break; C[i*j] = 1;
            if(i % j == 0){ Mu[i*j] = 0; break; }
            Mu[i*j] = Mu[i] * Mu[j];
        }
    }
}

ll pw(ll a, ll n) {
    ll ret=1;
    while(n) {
        if(n&1) ret=ret*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,a;i<=N;i++) cin >> a, A[a]++;
    for(int i=1;i<=1'000'000;i++) for(int j=i;j<=1'000'000;j+=i) M[i]+=A[j];
    Sieve();
    for(int i=1;i<=1'000'000;i++) for(int j=i;j<=1'000'000;j+=i) Co[j]+=Mu[i]*M[i];
    cin >> Q;
    for(int i=1,a;i<=Q;i++) {
        cin >> a;
        cout << pw(2,Co[a]) << '\n';
    }
    return 0;
}