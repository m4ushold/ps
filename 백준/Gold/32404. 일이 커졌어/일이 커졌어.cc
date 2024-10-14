#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n+1);
    int a=n/2;
    for(int i=2;i<=n;i+=2) v[i]=a--;
    a=n/2;
    for(int i=1;i<=n;i+=2) v[i]=++a;
    for(int i=1;i<=n;i++) cout << v[i] << ' ';
    return 0;
}