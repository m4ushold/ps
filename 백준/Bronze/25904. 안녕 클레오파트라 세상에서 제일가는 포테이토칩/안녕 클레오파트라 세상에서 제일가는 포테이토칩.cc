#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,x; cin >> n >> x;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int i=0;
    while(x <= v[i]) i=(i+1)%n, x++;
    cout << i+1;
    return 0;
}