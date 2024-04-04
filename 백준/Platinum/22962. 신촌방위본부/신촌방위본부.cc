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

bool isInConvexHull(const Polygon& v, const Point pt) {
    if(ccw(v[0],v[1],pt)<0) return 0;
    int l=1, r=v.size()-1;
    while(l<r) {
        int m=(l+r+1)/2;
        if(ccw(v[0],v[m],pt)>=0) l=m;
        else r=m-1;
    }
    if(l==v.size()-1) return ccw(v[0], v.back(), pt)==0 && v[0]<=pt && pt<=v.back();
    return ccw(v[0],v[l],pt)>=0 && ccw(v[l],v[l+1],pt)>=0 && ccw(v[l+1],v[0],pt)>=0;
}

ll operator / (Point p1, Point p2){ return p1.x * p2.y - p2.x * p1.y; } // 외적
ll PolygonArea(const Polygon &v){
    ll res = 0;
    for(int i=0; i<v.size(); i++) res += v[i] / v[(i+1)%v.size()];
    return abs(res);
}

int count(Point a, Point b) {
    return gcd(abs(a.x-b.x), abs(a.y-b.y));
}
bool onLine(Point& a, Point& b, Point& c) { return min(a.x,b.x)<=c.x&&c.x<=max(a.x,b.x) && min(a.y,b.y)<=c.y&&c.y<=max(a.y,b.y)?!ccw(a,b,c):0; }

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    Polygon v(n);
    for(auto &[a,b]:v) cin >> a >> b;
    v=convexHull(v);

    Polygon s(m);
    for(auto &[a,b]:s) cin >> a >> b;

    ll cnt=0, b=0;
    if(v.size()==1) {
        cnt=1;
        for(auto i:s) if(i==v[0]) cnt=0;
        cout << cnt;
    } else if(v.size()==2) {
        cnt=count(v[0],v[1])+1;
        for(auto i:s) if(onLine(v[0],v[1],i)) cnt--;
        cout << cnt;
    } else {
        for(auto [a,b]:s) cnt+=isInConvexHull(v,{a,b});
        for(int i=0;i<v.size();i++) b+=count(v[i],v[(i+1)%v.size()]);
        cout << (PolygonArea(v) + b + 2)/2 - cnt;
    }
    return 0;
}