#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if(n&1) return cout << "Bob", 0;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end(),greater<>());
    ll a=0,b=0;
    for(int i=0;i<n;i++) {
        if(i<n/2) a+=v[i];
        else b+=v[i];
    }
    if(a > b) cout << "Alice";
    else cout << "Bob";
    return 0;
}