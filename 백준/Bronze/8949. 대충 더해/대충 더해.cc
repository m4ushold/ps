#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b; cin >> a >> b;
    vector<int> v;
    while(a || b) {
        v.push_back(a%10+b%10);
        a/=10, b/=10;
    }
    reverse(v.begin(),v.end());
    for(int i:v) cout << i;
    return 0;
}