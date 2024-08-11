#include <bits/stdc++.h>
using namespace std;

bool chk(vector<int> a, vector<int> b) {
    for(int i=0;i<5;i++) if(a[i]==b[i]) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(5));
    for(auto &vec:v) for(auto &i:vec) cin >> i;

    int mx=-1, dap=0;
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<n;j++) if(i!=j) cnt+=chk(v[i], v[j]);
        if(mx < cnt) mx=cnt, dap=i+1;
    }
    cout << dap;
    return 0;
}