#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &[a,b]:v) cin >> a >> b;
    sort(v.begin(),v.end());
    int mn=1e9, cnt=0;
    for(auto [a,b]:v) {
        if(mn>b) cnt++, mn=b;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}