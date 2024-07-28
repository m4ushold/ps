#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    map<string,int> m;
    int n; cin >> n;
    for(int i=0,a;i<n;i++) {
        string s; cin >> s >> a;
        m[s]+=a;
    }
    for(auto [i,j]:m) if(j==5) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}