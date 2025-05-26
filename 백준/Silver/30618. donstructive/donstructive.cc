#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a,b;
    for(int i=1;i<=n;i+=2) a.push_back(i);
    for(int i=2;i<=n;i+=2) b.push_back(i);
    reverse(b.begin(),b.end());
    for(int i:a) cout << i << ' ';
    for(int i:b) cout << i << ' ';
    return 0;
}