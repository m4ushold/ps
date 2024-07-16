#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, c; cin >> n >> c;
    vector<int> v(c+1);
    for(int i=0;i<n;i++) {
        int a; cin >> a;
        for(int j=a;j<=c;j+=a) v[j]=1;
    }
    cout << reduce(v.begin(),v.end());
    return 0;
}