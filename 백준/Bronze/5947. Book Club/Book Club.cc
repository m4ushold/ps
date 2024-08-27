#include <bits/stdc++.h>
using namespace std;

int A[50505][55];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,p; cin >> n >> m >> p;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];
    vector<pair<int,int>> q(p);
    for(auto &[i,j]:q) cin >> i >> j;
    int dap=0;
    for(int i=0,t;i<n;i++) {
        t=1;
        for(int j=0;j<p;j++) if(A[i][q[j].first-1]!=q[j].second) t=0;
        if(t) dap++;
    }
    cout << dap;
    return 0;
}