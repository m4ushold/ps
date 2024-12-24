#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<string,string> m;
    for(int i=0;i<n;i++) {
        string a,b; cin >> a >> b >> b;
        m[a]=b;
    }
    int t; cin >> t;
    while(t--) {
        int k; cin >> k;
        string s;
        while(k--) cin >> s, cout << m[s] << ' ';
        cout << '\n';
    }
    return 0;
}