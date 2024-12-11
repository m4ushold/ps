#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int a=0, e=0, o=0;
    for(int i:v) if((i&1) == (a&1)) e++, a++;
    a=1;
    for(int i:v) if((i&1) == (a&1)) o++, a++;
    cout << max(o,e);
    return 0;
}