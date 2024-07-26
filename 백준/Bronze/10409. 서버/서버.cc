#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,t; cin >> n >> t;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int cnt=0, s=0;
    for(int i=0;i<n;i++) {
        s+=v[i];
        if(s<=t) cnt++;
    }
    cout << cnt;
    return 0;
}