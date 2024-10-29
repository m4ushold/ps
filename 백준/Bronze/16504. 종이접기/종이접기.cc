#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n*n);
    for(int &i:v) cin >> i;
    cout << accumulate(v.begin(),v.end(),0LL);
    return 0;
}