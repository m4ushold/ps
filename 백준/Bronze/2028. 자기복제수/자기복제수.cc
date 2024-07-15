#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool f(string n) {
    string s=to_string(stoi(n)*stoi(n));
    return s.substr(s.size()-n.size()) == n;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << (f(to_string(n)) ? "YES\n" : "NO\n");
    }
    return 0;
}