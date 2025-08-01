#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) {
        cin >> i;
        if(i&1) return cout << "Alice", 0;
    }
    cout << "Dmitry";
    return 0;
}