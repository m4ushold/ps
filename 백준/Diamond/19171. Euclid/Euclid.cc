#include <bits/stdc++.h>
using namespace std;
using lf=long double;

struct point {
    lf x,y,z;
} a,b,c;

point operator*(point p, lf c) {return point{c*p.x,c*p.y,c*p.z};}
point operator-=(point &p, point b) {
    p.x-=b.x, p.y-=b.y, p.z-=b.z;
    return p;
}

lf dist(point a, point b) {
    lf dx=a.x-b.x, dy=a.y-b.y, dz=a.z-b.z;
    return sqrt(dx*dx+dy*dy+dz*dz);
}

lf err(point p) {
    return dist(a,p)+dist(b,p)+dist(c,p);
}

point calc_grad(point p) {
    lf aa=dist(a,p), bb=dist(b,p), cc=dist(c,p);
    if(aa<1e-8 || bb<1e-8 || cc<1e-8) return point{0,0,0};
    lf x = (p.x-a.x)/aa + (p.x-b.x)/bb + (p.x-c.x)/cc;
    lf y = (p.y-a.y)/aa + (p.y-b.y)/bb + (p.y-c.y)/cc;
    lf z = (p.z-a.z)/aa + (p.z-b.z)/bb + (p.z-c.z)/cc;
    return {x,y,z};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a.x >> a.y >> a.z;
    cin >> b.x >> b.y >> b.z;
    cin >> c.x >> c.y >> c.z;

    point f_p = point{(a.x+b.x+c.x)/3, (a.y+b.y+c.y)/3, (a.z+b.z+c.z)/3};
    lf a = 1e6;
    point grad;
    for(int iter=0;iter<27182;iter++) {
        grad = calc_grad(f_p);
        f_p -= grad*a;
        a*=0.999;
    }
    cout << fixed << setprecision(12) << err(f_p);
    return 0;
}