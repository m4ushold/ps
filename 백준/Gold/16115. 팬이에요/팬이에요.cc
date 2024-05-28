#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;
using Polygon=vector<Point>;

const Point P={0,0};

ll dist(Point p1, Point p2=P) {
    ll dx=p2.x-p1.x, dy=p2.y-p1.y;
    return dx*dx+dy*dy;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Polygon v;
    ll d=0;
    for(ll i=0,a,b;i<n;i++) {
        cin >> a >> b;
        if(dist({a,b}) > d) v.clear(), v.push_back({a,b}), d=dist({a,b});
        else if(dist({a,b})==d) v.push_back({a,b});
    }
    
    vector<double> p,q;
    for(auto [a,b]:v) p.push_back(atan2(a,b)*180/M_PI);
    for(int i=0;i<p.size();i++) q.push_back(p[i]-p[(i+1)%p.size()]);
    for(auto &i:q) {
        while(i<=0) i+=360;
        while(i>360) i-=360;
    }
    cout << fixed << setprecision(12) << *max_element(q.begin(),q.end());

    return 0;
}