#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string a,b; cin >> a >> b;
    for(int i=0;i<a.size();i++) {
        if((a[i]!=b[i]) ^ (n&1)) {
            cout << "Deletion failed";
            return 0;
        }
    }
    cout << "Deletion succeeded";
    return 0;
}