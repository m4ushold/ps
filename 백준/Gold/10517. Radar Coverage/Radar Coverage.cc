#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using llf=long double;
using Point=pair<llf,llf>;
using Circle=pair<Point,llf>;

Point operator+ (Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator- (Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator* (llf k, Point a) { return Point(k*a.x, k*a.y); }
llf operator* (Point a, Point b) { return a.x*a.x + a.y*a.y; }
llf operator/ (Point a, Point b) { return a.x*b.y - a.y*b.x; }
llf dst(Point a, Point b) { return hypot(a.x-b.x, a.y-b.y); }

Point center(Point a, Point b) { return Point((a.x+b.x)/2, (a.y+b.y)/2); }
Point center(Point a, Point b, Point c) {
    Point aa = b - a, bb = c - a;
    auto c1 = aa*aa * 0.5, c2 = bb*bb * 0.5;
    auto d = aa / bb;
    auto x = a.x + (c1 * bb.y - c2 * aa.y) / d;
    auto y = a.y + (c2 * aa.x - c1 * bb.x) / d;
    return Point(x, y);
}

Circle MEC(vector<Point> v) {
    Point p = {0, 0};
    llf r = 0; int n = v.size();
    for(int i=0; i<n; i++) if(dst(p, v[i]) > r) {
        p = v[i]; r = 0;
        for(int j=0; j<i; j++) if(dst(p, v[j]) > r) {
            p = center(v[i], v[j]); r = dst(p, v[i]);
            for(int k=0; k<j; k++) if(dst(p, v[k]) > r) {
                p = center(v[i], v[j], v[k]);
                r = dst(v[k], p);
            }
        }
    }
    return {p, r};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        vector<Point> v(3);
        for(auto &[a,b]:v) cin >> a >> b;

        Circle res=MEC(v);
        cout << fixed << setprecision(2) << "Case #" << i << ": " << res.x.x << ' ' << res.x.y << '\n';
    }
    return 0;
}