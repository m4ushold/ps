#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;
using Polygon=vector<Point>;

ll operator / (Point p1, Point p2){ return p1.x * p2.y - p2.x * p1.y; }
ll PolygonArea(const Polygon &v){
    ll res = 0;
    for(int i=0; i<v.size(); i++) res += v[i] / v[(i+1)%v.size()];
    return abs(res);
}

ll cnt(Point a, Point b) { return gcd(abs(a.x-b.x),abs(a.y-b.y)); }

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    Point a,b,c;
    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
        if(!a.x && !a.y && !b.x && !b.y && !c.x && !c.y) break;
        int A=PolygonArea({a,b,c});
        int B=cnt(a,b)+cnt(b,c)+cnt(c,a);
        cout << (A-B+2)/2 << '\n';
    }
    return 0;
}