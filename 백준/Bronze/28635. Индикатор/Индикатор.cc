#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m,a,b; cin >> m >> a >> b;
    cout << (b-a+m)%m;
    return 0;
}