#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol() {
    ll a,b,c,d; cin >> a >> b >> c >> d;
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    ll e=a, f=a, g=a, t=3*a+d - (a+b+c);
    if(t > 0) { // reduce
        e-=t/3, f-=t/3, g-=t/3;
        t%=3;
        if(t==1) g--;
        else if(t==2) e--, f--;
    } else {
        t=-t;
        f+=t/2, g+=t+1>>1;
        g+=f-min(f,b);
        f=min(f,b);
    }
    cout << e*f*g << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}