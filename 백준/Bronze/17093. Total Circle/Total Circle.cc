#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;

ll dist(Point a, Point b) {
    ll dx=a.first-b.first, dy=a.second-b.second;
    return dx*dx+dy*dy;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<Point> p(n), q(m);
    for(auto &[a,b]:p) cin >> a >> b;
    for(auto &[a,b]:q) cin >> a >> b;
    ll mx=0;
    for(auto a:q) for(auto b:p) mx=max(mx,dist(a,b));
    cout << mx;
    return 0;
}