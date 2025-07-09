#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    sort(v.begin(),v.end(),[](auto a, auto b) {
        return a.length() < b.length();
    });
    int ans=n;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(v[j].substr(0,v[i].size()) == v[i]) {
                ans--;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}