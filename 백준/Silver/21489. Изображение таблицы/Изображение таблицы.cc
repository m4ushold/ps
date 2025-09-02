#include <bits/stdc++.h>
using namespace std;
using ll=long long;

char A[606][303];

void sol(int tc) {
    int n; cin >> n;
    vector<vector<int>> v(n);
    for(auto &vec:v) {
        int m; cin >> m;
        vec.resize(m);
        for(int &i:vec) cin >> i;
    }

    int mx=0;

    for(int i=0;i<n;i++) {
        // 2i, 2i+1
        int idx=0;
        for(int j:v[i]) {
            A[2*i][idx]=A[i*2+2][idx]='+';
            A[2*i+1][idx]='|';
            idx++;
            for(int k=0;k<j;k++,idx++) {
                if(A[i*2][idx] == 0) A[i*2][idx]='-';
                A[i*2+2][idx]='-';
                A[i*2+1][idx]=' ';
            }
            A[2*i][idx]=A[2*i+2][idx]='+';
            A[2*i+1][idx]='|';
        }
        mx=max(mx,idx);
    }

    for(int i=0;i<2*n+1;i++) {
        for(int j=0;j<=mx;j++) {
            if(A[i][j]) cout << A[i][j];
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}