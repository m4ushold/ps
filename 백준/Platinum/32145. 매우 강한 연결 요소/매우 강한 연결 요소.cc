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
    if(l==v.size()-1) return 0;
    return ccw(v[0],v[l],pt)>=0 && ccw(v[l],v[l+1],pt)>0 && ccw(v[l+1],v[0],pt)>=0;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Polygon v(n);
    for(auto& [a,b]:v) cin >> a >> b;
    Polygon hull=convexHull(v);

    int h=n;
    for(auto i:v) {
        h-=isInConvexHull(hull, i);
        if(i!=v[0] && i!=v[1] && ccw(v[0],v[1],i)==0) h++;
    }
    cout << 3*n-3-h;
    return 0;
}