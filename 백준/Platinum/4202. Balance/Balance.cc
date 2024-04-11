#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<double,double>;
using Polygon=vector<Point>;

pair<double,double> polygon_centroid(Polygon &v) {
    int n=v.size();
    double cx = 0, cy = 0, area2 = 0;
    for(int i = 0, j = n - 1; i < n; j = i++) {
        double tri_area2 = v[i].x * v[j].y - v[i].y * v[j].x;
        cx += (v[i].x + v[j].x) * tri_area2;
        cy += (v[i].x + v[j].x) * tri_area2;
        area2 += tri_area2;
    }
    cx /= 3 * area2;
    cy /= 3 * area2;
    return {cx,cy};
};


Point operator + (Point p1, Point p2){ return {p1.x + p2.x, p1.y + p2.y}; }
Point operator - (Point p1, Point p2){ return {p1.x - p2.x, p1.y - p2.y}; }
double operator * (Point p1, Point p2){ return p1.x * p2.x + p1.y * p2.y; } // 내적
double operator / (Point p1, Point p2){ return p1.x * p2.y - p2.x * p1.y; } // 외적
int ccw(const Point& a, const Point& b, const Point& c) {
    ll res=a.x*b.y+b.x*c.y+c.x*a.y;
    res-=b.x*a.y+c.x*b.y+a.x*c.y;
    return (res>0)-(res<0);
}

bool cross(Point& a, Point& b, Point& c, Point& d) {
    int ab=ccw(a,b,c)*ccw(a,b,d);
    int cd=ccw(c,d,a)*ccw(c,d,b);
    if(ab==0&&cd==0) {
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        return !(b<c||d<a);
    }
    return ab<=0&&cd<=0;
}

int cross(Point s1, Point e1, Point s2, Point e2, pair<double, double> &res){
    if(!cross(s1, e1, s2, e2)) return 0;
    ll det = (e1 - s1) / (e2 - s2);
    if(!det){
        if(s1 > e1) swap(s1, e1);
        if(s2 > e2) swap(s2, e2);
        if(e1 == s2){ res = s2; return 1; }
        if(e2 == s1){ res = s1; return 1; }
        return -1;
    }
    res.x = s1.x + (e1.x - s1.x) * ((s2 - s1) / (e2 - s2) * 1.0 / det);
    res.y = s1.y + (e1.y - s1.y) * ((s2 - s1) / (e2 - s2) * 1.0 / det);
    return 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    deque<Point> dq;
    for(int i=0,a,b;i<n;i++) {
        cin >> a >> b;
        dq.push_back({a,b});
    }
    while(dq.front().second * dq.back().second > 0) dq.push_back(dq.front()), dq.pop_front();

    Polygon u,d;
    pair<double,double> a;
    cross(dq.front(),dq.back(), {-1e9,0}, {1e9,0}, a);
    u.push_back(a), d.push_back(a);
    for(auto iter=dq.begin();iter!=dq.end();iter++) {
        if(iter!=dq.begin()) {
            auto i = iter-1;
            if(iter->second*i->second < 0) {
                cross(*iter,*i, {-1e9,0}, {1e9,0}, a);
                u.push_back(a), d.push_back(a);
            }
        }
        auto b = *iter;
        if(iter->second > 0) u.push_back(*iter);
        else d.push_back(*iter);
    }

    double ce=polygon_centroid(u).x, clr =polygon_centroid(d).x;
    cout << fixed << setprecision(2);
    double e = 1e-7;
    if(clr-e < ce && ce < clr+e) cout << "Balanced.";
    else if(ce > clr) cout << "CE is forward of CLR by " << ce-clr << " units.";
    else cout << "CE is aft of CLR by " << clr-ce << " units.";
    return 0;
}