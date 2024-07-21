#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int p, m; cin >> p >> m;
        vector<int> v(p);
        for(int &i:v) cin >> i;

        set<int> s;
        int a=0;
        for(int i:v) a+=!s.insert(i).second;
        cout << a << '\n';
    }
    return 0;
}