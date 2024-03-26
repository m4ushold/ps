#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, Q, A[101010], B[101010], C[101010], MOD[101010];
string M;

ll m(int p) {
    ll res=0;
    for(char c:M) res=(res*10+c-'0')%p;
    return res;
}

ll calc() {
    memset(B, 0, sizeof B), memset(C, 0, sizeof C);
    for(int i=1;i<=N;i++) if(!C[i]) {
        int v=i, p=0;
        vector<int> vec;
        while(!C[v]) C[v]=1, vec.push_back(v), v=A[v], p++;

        for(int j=0;j<p;j++) B[vec[j]]=vec[(j+MOD[p])%p];
    }
    
    ll res=0;
    for(int i=1;i<=N;i++) res+=B[i]*i;
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<101010;i++) MOD[i]=m(i);

    cin >> Q;
    for(int q=0,a,i,j;q<Q;q++) {
        cin >> a;
        if(a&1) cin >> i >> j, swap(A[i], A[j]);
        else cout << calc() << '\n';
    }
    return 0;
}