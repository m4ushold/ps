#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    if(s=="(1)") cout << 0;
    else if(s==")1(") cout << 2;
    else cout << 1;
    return 0;
}