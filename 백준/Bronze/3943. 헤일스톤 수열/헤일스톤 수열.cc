#include <bits/stdc++.h>
using namespace std;

vector<char> A[303];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int mx=n;
        while(n>1) {
            if(n&1) n=n*3+1;
            else n/=2;
            mx=max(mx,n);
        }
        cout << mx << '\n';
    }
    return 0;
}