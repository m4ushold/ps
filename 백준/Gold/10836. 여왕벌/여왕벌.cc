#include <bits/stdc++.h>
using namespace std;

int M, N, A[1414], R[707], C[707];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> N;
    A[0]=1;
    for(int i=0;i<N;i++) {
        int a,b,c; cin >> a >> b >> c;
        if(b) A[a]++, A[a+b]++;
        else A[a+b]+=2;
    }
    for(int i=1;i<2*M;i++) A[i]+=A[i-1];
    for(int i=0;i<M;i++) R[M-i-1]=A[i];
    for(int i=M-1;i<2*M-1;i++) C[i-M+1]=A[i];
    
    for(int i=0;i<M;i++) {
        for(int j=0;j<M;j++) {
            if(!i) cout << C[j] << ' ';
            else if(!j) cout << R[i] << ' ';
            else cout << max(R[i], C[j]) << ' ';
        }
        cout << endl;
    }
    return 0;
}