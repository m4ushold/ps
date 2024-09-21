#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b,c; cin >> a >> c;
    for(char d:a) if(isalpha(d)) b+=d;
    for(int i=0;i+c.size()<=b.size();i++) {
        if(b.substr(i,c.size()) == c) {cout << 1; return 0;}
    }
    cout << 0;
    return 0;
}