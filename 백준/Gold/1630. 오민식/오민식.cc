#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=987654321;
int S[1010101]={1,1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> primes;
    for(int i=2;i*i<1010101;i++) if(!S[i]) for(int j=2*i;j<1010101;j+=i) S[j]=1;
    for(int i=2;i<1010101;i++) if(!S[i]) primes.push_back(i);

    int n; cin >> n;
    ll dap=1;
    for(int p:primes) {
        int t=n;
        while(t>=p) t/=p, dap=dap*p%MOD;
    }
    cout << dap;
    return 0;
}