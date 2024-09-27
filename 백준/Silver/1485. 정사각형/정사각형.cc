#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=pair<ll,ll>;

vec operator-(vec &a, vec &b) {
    return {a.first-b.first, a.second-b.second};
}

bool dot(vec a, vec b) {
    return a.first*b.first+a.second*b.second;
}

ll dist(vec a, vec b) {
    ll dx=a.first-b.first, dy=a.second-b.second;
    return dx*dx+dy*dy;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        vector<pair<ll,ll>> v(4);
        for(auto &[a,b]:v) cin >> a >> b;
        sort(v.begin(),v.end());
        ll f = dot(v[0]-v[1], v[0]-v[2]) + dot(v[3]-v[1], v[3]-v[2]);
        if(!f && dist(v[0],v[1])==dist(v[0],v[2])) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}