#include <bits/stdc++.h>
using namespace std;
using lf=double;
using Point=tuple<lf,lf,lf>;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n && n) {
        vector<Point> v(n);
        lf x,y,z,a=0.1,r=0;
        for(auto &[a,b,c]:v) cin >> a >> b >> c, x+=a, y+=b, z+=c;
        x/=n, y/=n, z/=n;
        
        for(int i=0,idx;i<27182;i++) {
            idx=r=0;
            for(int j=0;j<n;j++) {
                auto [xx,yy,zz]=v[j];
                lf dx=x-xx, dy=y-yy, dz=z-zz, d=sqrt(dx*dx+dy*dy+dz*dz);
                if(d>r) r=d, idx=j;
            }
            auto [xx,yy,zz]=v[idx];
            x+=(xx-x)*a, y+=(yy-y)*a, z+=(zz-z)*a;
            a*=0.999;
        }
        if(abs(r) < 1e-7) r = 0;
        cout << fixed << setprecision(12) << r << '\n';
    }
    
    return 0;
}