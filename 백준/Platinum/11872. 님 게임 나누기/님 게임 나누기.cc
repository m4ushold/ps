#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans=0;
    for(ll i=0,a;i<n;i++) {
        cin >> a;
        if(a%4==0) ans^=a-1;
        else if(a%4==3) ans^=a+1;
        else ans^=a;
    }
    cout << (ans?"koosaga":"cubelover");
    return 0;
}