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

ll LatticePoint(Polygon &v) {
    auto cnt=[](Point a, Point b) { return gcd(abs(a.x-b.x),abs(a.y-b.y)); };
    ll a=PolygonArea(v), b=0;
    for(int i=0;i<v.size();i++) b+=cnt(v[i], v[(i+1)%v.size()]);
    return max(a-b+2>>1,0LL) + b;
}

Point nxtPoint(Point a, int dir) {
    vector<Point> v({{0,1},{1,1},{1,0}, {1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}});
    return {a.x+v[dir].x, a.y+v[dir].y};
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin >> s) {
        Point a;
        Polygon v({a});
        for(char c:s) a=nxtPoint(a,c-'0'), v.push_back(a);
        cout << LatticePoint(v) << '\n';
    }
    return 0;
}