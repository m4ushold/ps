#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n; cin >> n;
    string a,b; cin >> a >> b;
    int ans=0;
    for(int i=0;i<n;i++) {
        ans+=min(abs(a[i]-b[i]),26-abs(a[i]-b[i]));
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}