#include <bits/stdc++.h>
using namespace std;

int N, X, Y, A[25], U[13];

int recur(int n=1, int len=1) {
    if(len == N) return 1;
    if(n == X || n == Y) return recur(n+1,len);
    if(A[n]) return recur(n+1,len);

    int res=0;
    for(int i=1;i<=N;i++) if(!U[i]) {
        if(A[n+i+1] || n+i+1 > 2*N) continue;
        if(n-A[n]-1 > 0 && A[n-A[n]-1] == A[n]) return 0;

        A[n]=A[n+i+1]=i, U[i]=1;
        res += recur(n+1, len+1);
        A[n]=A[n+i+1]=U[i]=0;
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> X >> Y;
    A[X] = A[Y] = Y-X-1;
    U[A[X]] = 1;
    cout << recur();
    return 0;
}