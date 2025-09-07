#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n; cin >> n;
    vector<int> v;
    if(n&1) v.push_back(3), n-=3;
    while(n) v.push_back(2), n-=2;
    cout << v.size() << '\n';
    for(int i:v) cout << i << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}