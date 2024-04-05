#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;
using Polygon=vector<Point>;

// pick's theorem
// A = i + b/2 -1;
ll operator / (Point p1, Point p2){ return p1.x * p2.y - p2.x * p1.y; }
ll PolygonArea(const Polygon &v){
    ll res = 0;
    for(int i=0; i<v.size(); i++) res += v[i] / v[(i+1)%v.size()];
    return abs(res);
}

// 다각형 내부의 점
ll LatticePointStrict(Polygon &v) {
    auto cnt=[](Point a, Point b) { return gcd(abs(a.x-b.x),abs(a.y-b.y)); };
    ll a=PolygonArea(v), b=0;
    for(int i=0;i<v.size();i++) b+=cnt(v[i], v[(i+1)%v.size()]);
    return max(a-b+2>>1,0LL);
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        Polygon v(3);
        for(auto &[a,b]:v) cin >> a >> b;
        cout << LatticePointStrict(v) << '\n';
    }
    return 0;
}