#include <bits/stdc++.h>
using namespace std;

void sol(int tc) {
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    
    while(n>2) {
        for(int i=0;i<=n/2;i++) v[i]+=v[n-i-1];
        n=n+1>>1;
    }
    cout << "Case #" << tc << ": " << (v[0] > v[1] ? "Alice" : "Bob") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}