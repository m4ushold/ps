#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll area(pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll> p3) {
    ll x1 = p1.first, y1 = p1.second;
    ll x2 = p2.first, y2 = p2.second;
    ll x3 = p3.first, y3 = p3.second;
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

vector<pair<ll,ll>> f(ll ax, ll ay, ll bx, ll by) {
    ll x=bx-ax, y=by-ay, g=gcd(x,y);
    if(g) x/=g, y/=g;
    if(g==1) return vector<pair<ll,ll>>();
    
    vector<pair<ll,ll>> res;
    ll a=min(ax,bx), b=max(ax,bx), c=min(ay,by), d=max(ay,by);
    if(a<=ax+x && ax+x<=b && c<=ay+y && ay+y<=d) {
        if(!(ax+x == bx && ay+y == by) && !(!x && !y)) res.push_back({ax+x,ay+y});
    }

    if(a<=bx-x && bx-x<=b && c<=by-y && by-y<=d) {
        if(!(bx-x == bx && by-y == by) && !(!x && !y)) res.push_back({bx-x,by-y});
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll ax,ay,bx,by,cx,cy; cin >> ax >> ay >> bx >> by >> cx >> cy;
    vector<pair<ll,ll>> a,b,c;
    a=f(ax,ay,bx,by);
    b=f(bx,by,cx,cy);
    c=f(ax,ay,cx,cy);

    ll mn=LLONG_MAX/2, mx=-1;
    for(auto aa:a) for(auto bb:b) for(auto cc:c) {
        ll ar=area(aa,bb,cc);
        mn=min(mn,ar), mx=max(mx,ar);
    }
    if(mx < 0) cout << -1;
    else cout << mx << ' ' << mn;
    return 0;
}