#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, tc=0;
    while(cin >> n && n) {
        cin.ignore();
        vector<string> v(n);
        for(auto &i:v) getline(cin, i);
        sort(v.begin(),v.end());
        cout << ++tc << '\n';
        for(auto i:v) cout << i << '\n';
    }
    return 0;
}