#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n; cin >> n;
    set<string> s;
    for(int i=0;i<n;i++) {
        string str; cin >> str;
        s.insert(str);
    }
    cout << s.size() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}