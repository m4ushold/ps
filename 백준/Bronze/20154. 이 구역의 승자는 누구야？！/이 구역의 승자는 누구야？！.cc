#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int dap=0;
    vector<int> v({3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1});
    for(char c:s) dap+=v[c-65];
    if(dap%2) cout << "I'm a winner!";
    else cout << "You're the winner?";
}