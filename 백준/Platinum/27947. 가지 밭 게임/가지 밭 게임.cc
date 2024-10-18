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

ll operator / (Point p1, Point p2){ return p1.x * p2.y - p2.x * p1.y; }

// 다각형의 넓이의 2배를 반환, 항상 정수, O(N)
ll PolygonArea(const Polygon &v){
    ll res = 0;
    for(int i=0; i<v.size(); i++) res += v[i] / v[(i+1)%v.size()];
    return abs(res);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, a; cin >> n >> a;
    Polygon v(3);
    for(auto& [a,b]:v) cin >> a >> b;
    for(ll i=0,a,b;i<n;i++) {
        cin >> a >> b;
        v.push_back({a,b});
    }

    auto all = convexHull(v);
    if(PolygonArea(all) < a*2) {
        cout << "draw";
        return 0;
    }

    int l=4, r=v.size();
    while(l<r) {
        int m=l+r>>1;
        auto hull=convexHull(Polygon(v.begin(),v.begin()+m));
        if(PolygonArea(hull) >= 2*a) r=m;
        else l=m+1;
    }
    if(~r&1) cout << "wapas";
    else cout << "wider";
    return 0;
}