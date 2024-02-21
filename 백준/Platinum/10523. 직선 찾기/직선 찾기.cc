#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;

vector<Point> V;

int ccw(const Point& a, const Point& b, const Point& c) {
    ll res=a.x*b.y+b.x*c.y+c.x*a.y;
    res-=b.x*a.y+c.x*b.y+a.x*c.y;
    return (res>0)-(res<0);
}

int cnt(Point p, Point q) {
    int res=0;
    for(Point r:V) res+=!ccw(p,q,r);
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, p; cin >> n >> p;
    int d=n*p/100 + !!(n*p%100);
    V.resize(n);
    for(auto &[i,j]:V) cin >> i >> j;
    if(n == 1){ cout << "possible"; return 0; }

    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<> r(0,n-1);
    for(int i=0,j,k;i<1000;i++) {
        j=r(g), k=r(g);
        if(j==k) continue;
        if(cnt(V[j], V[k]) >= d) {
            cout << "possible";
            return 0;
        }
    }
    cout << "impossible";

    return 0;
}