#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a,b; cin >> a >> b;
    for(int i=0;i<max(a,b)-min(a,b);i++) cout << 1;
    for(int i=0;i<min(a,b);i++) cout << 2;
    return 0;
}