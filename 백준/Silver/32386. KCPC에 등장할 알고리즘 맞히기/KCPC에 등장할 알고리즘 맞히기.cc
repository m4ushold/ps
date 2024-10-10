#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    map<string,int> m;
    for(int i=0;i<n;i++) {
        int a,b; cin >> a >> b;
        string s;
        for(int j=0;j<b;j++) cin >> s, m[s]++;
    }
    int mx=0, cnt=0;
    string ss;
    for(auto [i,j]:m) {
        if(mx<j) mx=j, cnt=1, ss=i;
        else if(mx==j) cnt++;
    }
    if(cnt>1) cout << -1;
    else cout << ss;
    return 0;
}