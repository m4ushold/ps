#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n,k; cin >> n >> k;
    if(k==1) {
        if(n<4) cout << "-1\n";
        else {
            for(int i=2;i<=n;i+=2) cout << i << ' ';
            for(int i=1;i<=n;i+=2) cout << i << ' ';
            cout << '\n';
        }
    } else {
        for(int i=1;i<=n;i++) cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}