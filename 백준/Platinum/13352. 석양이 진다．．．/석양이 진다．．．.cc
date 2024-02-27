#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;

int ccw(const Point& a, const Point& b, const Point& c) {
    ll res=a.x*b.y+b.x*c.y+c.x*a.y;
    res-=b.x*a.y+c.x*b.y+a.x*c.y;
    return (res>0)-(res<0);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    if(n<3) {cout << "success"; return 0;}
    vector<Point> v(n);
    for(auto &[a,b]:v) cin >> a >> b;
    
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<> r(0,n-1);

    int f=0;
    for(int i=0;i<50;i++) {
        vector<Point> c;
        int a=r(g), b=r(g);
        while(a==b) b=r(g);
        for(int j=0;j<n;j++) if(ccw(v[a],v[b],v[j])) c.push_back(v[j]);
        int t=0;
        for(int j=2;j<c.size();j++) if(ccw(c[0],c[1],c[j])) {t=1; break;}
        if(t) continue;
        
        f=1;
        break;
    }
    
    cout << (f?"success":"failure");
    return 0;
}