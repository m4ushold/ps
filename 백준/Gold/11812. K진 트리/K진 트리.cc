#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, K, Q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K >> Q;
    while(Q--) {
        ll u,v; cin >> u >> v;
        int cnt=0;
        if(K==1) {
            cout << abs(u-v) << '\n';
            continue;
        }
        while(u^v) {
            if(u > v) swap(u, v);
            v = (v+K-2)/K;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}