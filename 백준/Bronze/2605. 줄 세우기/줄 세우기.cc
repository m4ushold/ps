#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for(int i=1,a;i<=n;i++) {
        cin >> a;
        v.insert(v.begin()+i-a-1, i);
    }
    for(int i:v) cout << i << ' ';
    return 0;
}