#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct pt {
    double x, y;
};

struct bc {
    double u, v, w;
};

bc calculateBarycentric(const pt& p, const pt& a, const pt& b, const pt& c) {
    pt v0 = {b.x - a.x, b.y - a.y};
    pt v1 = {c.x - a.x, c.y - a.y};
    pt v2 = {p.x - a.x, p.y - a.y};

    ll d00 = v0.x * v0.x + v0.y * v0.y;
    ll d01 = v0.x * v1.x + v0.y * v1.y;
    ll d11 = v1.x * v1.x + v1.y * v1.y;
    ll d20 = v2.x * v0.x + v2.y * v0.y;
    ll d21 = v2.x * v1.x + v2.y * v1.y;

    double d = d00 * d11 - d01 * d01;

    if (abs(d) < 1e-5) {
        return {-1.0, -1.0, -1.0};
    }

    double v = (d11 * d20 - d01 * d21) / d;
    double w = (d00 * d21 - d01 * d20) / d;
    double u = 1.0 - v - w;

    return {u, v, w};
}

int main() {
    int n; cin >> n;
    pt p,a,b,c; cin >> p.x >> p.y;
    vector<pt> v(n);
    for(auto &[x,y]:v) cin >> x >> y;

    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) {
        auto [x,y,z] = calculateBarycentric(p,v[i],v[j],v[k]);
        cout << setprecision(12);
        if(x>-1e-9 && y>-1e-9 && z>-1e-9) {
            for(int l=0;l<n;l++) {
                if(l==i) cout << fabs(x) << "\n";
                else if(l==j) cout << fabs(y) << '\n';
                else if(l==k) cout << fabs(z) << '\n';
                else cout << 0.0 << '\n';
            }
            return 0;
        }
    }
    return 0;
}