#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    int dap=0;
    for(int &i:a) cin >> i, dap+=abs(i);
    for(int &i:b) cin >> i, dap+=abs(i);
    cout << dap;
    return 0;
}