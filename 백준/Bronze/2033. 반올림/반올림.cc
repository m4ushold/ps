#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    int cnt=0;
    while(n>9) {
        if(n%10 >= 5) n+=10;
        n/=10, cnt++;
    }
    cout << n << string(cnt,'0');
    return 0;
}