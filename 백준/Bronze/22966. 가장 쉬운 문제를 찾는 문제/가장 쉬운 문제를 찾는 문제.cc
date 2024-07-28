#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int mn=1e9;
    string dap;
    for(int i=0,a;i<n;i++) {
        string s; cin >> s >> a;
        if(mn > a) mn=a, dap=s;
    }
    cout << dap;
    return 0;
}