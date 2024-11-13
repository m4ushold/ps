#include <bits/stdc++.h>
using namespace std;

int N, S, C[11][11];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> S;
    C[0][0]=1;
    for(int i=1;i<=10;i++) {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    vector<int> v(N);
    iota(v.begin(),v.end(),1);
    do {
        int s=0;
        for(int i=0;i<N;i++) s+=v[i]*C[N-1][i];
        if(s==S) break;
    } while(next_permutation(v.begin(),v.end()));
    for(int i:v) cout << i << ' ';
    return 0;
}