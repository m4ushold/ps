#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i, i-=2;
    
    string a,b; cin >> a;
    b=(a=="Whiteking")?"Blackking":"Whiteking";
    ll dap=reduce(v.begin(),v.end(),0,bit_xor<int>());
    cout << (dap ? a : b);
    return 0;
}