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

Point operator - (Point p1, Point p2){ return {p1.x - p2.x, p1.y - p2.y}; }
ll operator / (Point p1, Point p2){ return p1.x * p2.y - p2.x * p1.y; } // 외적

ll tArea(Point a, Point b, Point c) {
    ll res=a.x*b.y+b.x*c.y+c.x*a.y;
    res-=b.x*a.y+c.x*b.y+a.x*c.y;
    return abs(res);
}

ll f(Polygon &hull) {
    Point a=hull.front(), b=hull.back();
    ll s=1,e=hull.size()-2, mx=0;
    while(e-s>=3) {
        ll m1=(s*2+e)/3, m2=(s+e*2)/3;
        if(tArea(a,b,hull[m1])<=tArea(a,b,hull[m2])) s=m1;
        else e=m2;
    }

    for(int i=s;i<=e;i++) mx=max(mx,tArea(a,b,hull[i]));
    return mx;
}

ll calc(int s, int e, Polygon &hull) {
    int n=hull.size();
    Polygon a,b;
    for(int i=s;i!=e;i=(i+1)%n) a.push_back(hull[i]);
    a.push_back(hull[e]);
    for(int i=e;i!=s;i=(i+1)%n) b.push_back(hull[i]);
    b.push_back(hull[s]);
    return f(a)+f(b);
}

ll Calipers(Polygon hull) {
    int n = hull.size();
    ll mx = 0;
    for(int i=0, j=0; i<n; i++){
        while(j + 1 < n && (hull[i+1] - hull[i]) / (hull[j+1] - hull[j]) >= 0){
            mx = max(mx,calc(i,j++,hull));
        }
        mx = max(mx,calc(i,j,hull));
    }
    return mx;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        Polygon v(n);
        for(auto& [a,b]:v) cin >> a >> b;
        ll dap=Calipers(convexHull(v));
        cout << dap/2 << (dap&1 ? ".5\n" : "\n");
    }
    return 0;
}