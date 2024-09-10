#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int S[101010]={1,1};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<int> primes;
    for(int i=2;i*i<=77777;i++) if(!S[i]) {
        primes.push_back(i);
        for(int j=2*i;j<=77777;j+=i) S[j]=1;
    }
    int cnt=0;
    for(int i=1;i<=N;i++) {
        int t=i;
        for(int p:primes) while(t%(p*p)==0) t/=p*p;
        cnt+=sqrt(M/t);
    }
    cout << cnt;
    return 0;
}