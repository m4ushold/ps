#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;

    int ans=1e9;
    for(int i=0,t;i<=100-17;i++) {
        t=0;
        for(int j=0;j<n;j++) {
            if(v[j]<i) t+=(i-v[j])*(i-v[j]);
            if(v[j]>i+17) t+=(v[j]-i-17)*(v[j]-i-17);
        }
        ans=min(ans,t);
    }
    cout << ans;
    return 0;
}