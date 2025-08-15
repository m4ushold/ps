#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    ll n,k; cin >> n >> k;
    vector<ll> d(4);
    for(ll &i:d) cin >> i;
    vector<priority_queue<ll>> v(4);
    for(int i=0,x;i<n;i++) {
        char c; cin >> c >> x;
        v[c-'A'].push(x);
    }

    for(int i=0;i<k;i++) {
        array<ll,3> x={0,1,0};
        for(int j=0;j<4;j++) if(v[j].size()) {
            if(v[j].top() * x[1] > d[j] * x[0]) {
                x={v[j].top(),d[j],j};
            }
        }

        int j=x[2];
        cout << (char)(j+'A') << ' ' << v[j].top() << '\n';
        d[j]+=v[j].top();
        v[j].pop();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}