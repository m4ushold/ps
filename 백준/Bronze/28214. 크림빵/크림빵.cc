#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,p; cin >> n >> k >> p;
    int dap=0;
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0,a;j<k;j++) cin>> a, cnt+=!a;
        if(cnt<p) dap++;
    }
    cout << dap;
    return 0;
}