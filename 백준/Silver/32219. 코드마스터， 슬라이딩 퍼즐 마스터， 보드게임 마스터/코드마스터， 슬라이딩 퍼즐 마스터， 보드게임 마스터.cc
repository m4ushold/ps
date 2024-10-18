#include <bits/stdc++.h>
using namespace std;

void sol() {
    int x,y; cin >> x >> y;
    if(x==y) {
        cout << "dohoon\n";
        return ;
    }
    cout << "jinseo\n";
    cout << min(x,y) << ' ' << min(x,y) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}