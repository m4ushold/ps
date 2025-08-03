#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        string s; cin >> s;
        if(s == "mumble") continue;
        if(stoi(s) != i) {
            cout << "something is fishy";
            return;
        }
    }
    cout << "makes sense";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}