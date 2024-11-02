#include <bits/stdc++.h>
using namespace std;

int f(string s, int d) {
    if(d>=2) return 2;
    int i=0, j=s.length()-1;
    while(s[i]==s[j] && i<j) i++,j--;
    return i>=j||s.length()<2?d:min(f(s.substr(i+1,j-i),d+1), f(s.substr(i,j-i),d+1));
}

void sol() {
    string s; cin >> s;
    cout << f(s,0) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}