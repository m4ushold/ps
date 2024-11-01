#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int ans=0;
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<n;j++) {
            if(v[j]>=v[i] && v[j]-v[i]<=k) cnt++;
        }
        ans=max(ans, cnt);
    }
    cout << ans;
    return 0;
}