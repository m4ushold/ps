#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;

    int mx=2, tmp=2;
    for(int i=0;i<n-2;i++) {
        if(v[i]<=v[i+1] && v[i+1]<=v[i+2]) tmp=2;
        else if(v[i]>=v[i+1] && v[i+1]>=v[i+2]) tmp=2;
        else tmp++;
        mx=max(mx, tmp);
    }
    cout << mx;
    return 0;
}