#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll ccw(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c) {
    ll res=a.first*b.second+b.first*c.second+c.first*a.second;
    res-=b.first*a.second+c.first*b.second+a.first*c.second;
    return (res>0)-(res<0);
}

ll calc(const ll x, const ll y, const vector<tuple<ll,ll,ll>> &v) {
    vector<tuple<ll,ll,ll>> pts;
    for(auto [a,b,c]:v) if(c!=y) {
        ll len=abs(b-a);
        if(c>y) a=2*x-a, b=2*x-b, c=2*y-c, swap(a,b);

        pts.push_back({a,c,len});
        pts.push_back({b,c,-len});
    }
    
    sort(pts.begin(), pts.end(), [&](tuple<ll,ll,ll> a, tuple<ll,ll,ll> b){
        auto [ax,ay,af]=a;
        auto [bx,by,bf]=b;
        ll f=ccw({x,y},{ax,ay},{bx,by});
        if(f == 0) return af > bf;
        return f == 1;
    });

    ll res=0, tmp=0;
    for(auto [i,j,k]:pts) tmp+=k, res=max(res, tmp);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vector<tuple<ll,ll,ll>> v(n);
    for(auto &[a,b,c]:v) {
        cin >> a >> b >> c;
        if(a>b) swap(a,b);
    }

    ll mx=0;
    for(auto [a,b,c]:v) mx=max({mx, b-a+calc(a,c,v), b-a+calc(b,c,v)});
    cout << mx;
    return 0;
}