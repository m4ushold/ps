#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int cnt=0, mx=0;
    string dap;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        int k,m; cin >> k >> m;
        int ev=0;
        while(k<=m) m-=k, m+=2, ev++;
        cnt+=ev;
        if(ev > mx) mx=ev, dap=s;
    }
    cout << cnt << '\n' << dap;
}