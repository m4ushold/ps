#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, L, M[1'024'000], A[256], B[256], C[256], R[256];
random_device rd;
mt19937 g(rd());
uniform_int_distribution<int> r(0,1);

inline int idx(int i, int j) { return i*L+j; }

bool chk(int k) {
    for(int iter=0;iter<50;iter++) {
        for(int i=0;i<N;i++) R[i]=r(g), A[i]=B[i]=C[i]=0;
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) B[i]+=M[idx(i,k+N+j)]*R[j];
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) A[i]+=M[idx(i,k+j)]*B[j];
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) C[i]+=M[idx(i,k+N*2+j)]*R[j];
        for(int i=0;i<N;i++) if(A[i]!=C[i]) return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L;
    for(int i=0;i<N*L;i++) cin >> M[i];

    int cnt=0;
    for(int i=0;i<=L-3*N;i++) if(chk(i)) cnt+=3*N*N, i+=3*N-1;
    cout << cnt;
    return 0;
}