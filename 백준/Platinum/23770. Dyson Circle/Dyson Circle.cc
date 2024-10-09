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

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Polygon v(n);
    for(auto& [a,b]:v) cin >> a >> b;
    v=convexHull(v);
    n=v.size();
    ll dap=0, a=LLONG_MIN, b=LLONG_MIN, c=LLONG_MIN, d=LLONG_MIN;
    for(auto p:v) {
        a=max(a,p.x+p.y);
        b=max(b,p.x-p.y);
        c=max(c,-p.x+p.y);
        d=max(d,-p.x-p.y);
    }
    dap=4+a+b+c+d;
    
    if(n==2 && abs(v[0].x-v[1].x) == abs(v[0].y-v[1].y)) dap++;
    cout << dap;
    return 0;
}