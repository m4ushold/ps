#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, e; cin >> n >> e;
    vector<int> r(n);
    for(int &i:r) cin >> i;

    long double PI = acosl(-1.0L);
    ll ans = 0;
    for(int i : r) {
        if (2*i < e) {
            ans++;
            continue;
        }
            
        long double x = (long double)e / (2.0L * (long double)i);
        if(x < -1.0L) x = -1.0L;
        if(x > 1.0L) x =  1.0L;
        long double ang = asinl(x);
        long double t = PI / ang;

        ll add = (ll)floorl(t + 1e-21L);
        ans += add;
    }

    cout << ans;
    return 0;
}