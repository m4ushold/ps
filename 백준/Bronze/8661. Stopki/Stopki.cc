#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x,k,a; cin >> x >> k >> a;
    x%=(k+a);
    cout << (x<k);
    return 0;
}