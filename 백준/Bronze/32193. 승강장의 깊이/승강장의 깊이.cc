#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int a=0, b=0;
    for(int i=0,c,d;i<n;i++) {
        cin >> c >> d;
        a+=c, b+=d;
        cout << a-b << '\n';
    }
    return 0;
}