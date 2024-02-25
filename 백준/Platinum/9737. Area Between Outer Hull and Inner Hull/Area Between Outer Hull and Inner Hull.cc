#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<double,double>;
using Polygon=vector<Point>;

int ccw(const Point& a, const Point& b, const Point& c) {
    double res=a.x*b.y+b.x*c.y+c.x*a.y;
    res-=b.x*a.y+c.x*b.y+a.x*c.y;
    return (res>0)-(res<0);
}

double dist(Point p1, Point p2) {
    ll dx=p2.x-p1.x, dy=p2.y-p1.y;
    return hypot(dx,dy);
}

pair<Polygon,Polygon> convexHull(Polygon points) {
    swap(points[0], *min_element(points.begin(),points.end()));
    sort(points.begin()+1, points.end(), [&](auto a, auto b) {
        int dir=ccw(points[0],a,b);
        return dir?dir>0:dist(points[0],a)<dist(points[0],b);
    });
    Polygon stk, r;
    for(auto i:points) {
        while(stk.size()>=2 && ccw(stk[stk.size()-2], stk.back(), i)<=0) r.push_back(stk.back()), stk.pop_back();
        stk.push_back(i);
    }
    return {stk,r};
}

double operator / (Point p1, Point p2){ return p1.x * p2.y - p2.x * p1.y; }

// 다각형의 넓이의 2배를 반환, 항상 정수, O(N)
double PolygonArea(const Polygon &v){
    double res = 0;
    for(int i=0; i<v.size(); i++) res += v[i] / v[(i+1)%v.size()];
    return abs(res);
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    string id;
    int n;
    while(cin >> id >> n && n) {
        Polygon p(n), o, i;
        for(auto& [a,b]:p) cin >> a >> b;
        vector<Polygon> v;
        tie(o,p)=convexHull(p);
        tie(i,p)=convexHull(p);

        cout << fixed << setprecision(4) << "ProblemID " << id << ": " << (PolygonArea(o)-PolygonArea(i))/2 << '\n';
    }
    return 0;
}