#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end(),greater<>());
    int ans=0, cnt=0;
    for(int i:v) {
        ans += i-cnt;
        cnt++;
        k--;
        if(k == 0) break;
    }
    cout << ans;
    return 0;
}