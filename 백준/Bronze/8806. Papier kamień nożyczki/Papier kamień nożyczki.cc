#include <bits/stdc++.h>
using namespace std;
using lf=double;

lf f(lf a, lf b, lf c) {return a*b+b*c+c*a;}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        lf a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
        double aa=a*e+b*f+c*d, bb=d*b+e*c+f*a;
        if(aa>bb) cout << "ADAM";
        else if(aa<bb) cout << "GOSIA";
        else cout << "=";
        cout << '\n';
    }
    return 0;
}