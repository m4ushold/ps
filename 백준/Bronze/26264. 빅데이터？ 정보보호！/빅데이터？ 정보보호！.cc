#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string str; cin >> str;
    int i=0, s=0, b=0;
    while(i < str.size()) {
        if(str[i]=='s') i+=8, s++;
        else i+=7, b++;
    }
    if(b>=s) cout << "bigdata? ";
    if(s>=b) cout << "security!";
    return 0;
}