#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    cout << "NS"[*max_element(v.begin(),v.end()) == v[0]];
    return 0;
}