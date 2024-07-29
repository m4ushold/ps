#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int x=reduce(v.begin(),v.end(),0,bit_xor<int>());
    int dap=0;
    for(int i:v) if((x^i) < i) dap++;
    cout << dap;
    return 0;
}