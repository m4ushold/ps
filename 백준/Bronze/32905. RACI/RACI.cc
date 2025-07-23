#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    cin.ignore();
    for(int i=0;i<n;i++) {
        string s; getline(cin, s);
        int cnt=0;
        for(char c:s) if(c=='A') cnt++;
        if(cnt!=1) return cout << "No", 0;
    }
    cout << "Yes";
    return 0;
}