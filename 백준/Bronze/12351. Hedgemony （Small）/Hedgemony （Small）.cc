#include <bits/stdc++.h>
using namespace std;

void sol(int tc) {
    int n; cin >> n;
    vector<double> v(n);
    for(auto &i:v) cin >> i;
    for(int i=1;i<n-1;i++) v[i] = min((v[i-1]+v[i+1])/2,v[i]);
    cout << "Case #" << tc << ": " << fixed << setprecision(12) << v[n-2] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}