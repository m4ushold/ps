#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    int n; cin >> n;
    string s,t; cin >> s >> t;
    int b=0,w=0;
    for(int i=0;i<n;i++) if(s[i]!=t[i]) s[i]=='B' ? b++ : w++;
    cout << max(b,w) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}