#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll cnt=0;
    while(n>1) {
        if(n&1) n=3*n+1;
        else n/=2;
        cnt++;
    }
    cout << cnt;
    return 0;
}