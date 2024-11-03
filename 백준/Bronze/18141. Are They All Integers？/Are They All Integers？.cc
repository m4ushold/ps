#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) {
        if(i==j || j==k || k==i) continue;
        if((v[i]-v[j])%v[k]) return cout << "no", 0;
    }
    cout << "yes";
    return 0;
}