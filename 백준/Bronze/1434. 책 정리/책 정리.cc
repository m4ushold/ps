#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;
    cout << max(0,reduce(a.begin(),a.end())-reduce(b.begin(),b.end()));
    return 0;
}