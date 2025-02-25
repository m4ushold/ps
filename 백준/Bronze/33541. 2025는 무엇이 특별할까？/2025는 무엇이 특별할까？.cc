#include <bits/stdc++.h>
using namespace std;

bool chk(int n) {
    string s = to_string(n);
    int a = stoi(s.substr(0,2)), b=stoi(s.substr(2));
    int c = a+b;
    return c*c==n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=n+1;i<=9999;i++) {
        if(chk(i)) return cout << i, 0;
    }
    cout << -1;
    return 0;
}