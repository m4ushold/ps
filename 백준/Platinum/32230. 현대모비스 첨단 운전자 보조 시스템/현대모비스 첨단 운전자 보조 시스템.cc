#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;
using Polygon=vector<Point>;

int ccw(const Point& a, const Point& b, const Point& c) {
    ll res=a.x*b.y+b.x*c.y+c.x*a.y;
    res-=b.x*a.y+c.x*b.y+a.x*c.y;
    return (res>0)-(res<0);
}

ll dist(Point p1, Point p2) {
    ll dx=p2.x-p1.x, dy=p2.y-p1.y;
    return dx*dx+dy*dy;
}

Polygon convexHull(Polygon points) {
    swap(points[0], *min_element(points.begin(),points.end()));
    sort(points.begin()+1, points.end(), [&](auto a, auto b) {
        int dir=ccw(points[0],a,b);
        return dir?dir>0:dist(points[0],a)<dist(points[0],b);
    });
    Polygon stk;
    for(auto i:points) {
        while(stk.size()>=2 && ccw(stk[stk.size()-2], stk.back(), i)<=0) stk.pop_back();
        stk.push_back(i);
    }
    return stk;
}

ll operator / (Point p1, Point p2){ return p1.x * p2.y - p2.x * p1.y; } // 외적
ll PolygonArea(const Polygon &v){
    ll res = 0;
    for(int i=0; i<v.size(); i++) res += v[i] / v[(i+1)%v.size()];
    return abs(res);
}

const long double C=1-M_PI/3.0/sqrt(3);

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Polygon v(n);
    for(auto& [a,b]:v) cin >> a >> b;
    ll area = PolygonArea(convexHull(v));
    cout << fixed << setprecision(20) << area*C/6;
    return 0;
}