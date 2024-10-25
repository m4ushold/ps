#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll A[101][101];

// 0, 1, 2, 3
// l, u, r, d
vector<pair<ll,ll>> dd({
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
});

pair<ll,ll> nxt(ll x, ll y, ll dir) {
    return {x+dd[dir].first, y+dd[dir].second};
}

tuple<ll,ll,vector<pair<ll,ll>>> f(ll x, ll y, ll dir=0) {
    map<tuple<ll,ll,ll>,ll> vis;
    vector<pair<ll,ll>> res;

    int cnt=1;
    while(1) {
        vis[{x,y,dir}]=cnt;
        if(res.empty() || res.back().first!=x || res.back().second!=y) res.push_back({x,y});

        auto [nx, ny] = nxt(x,y,dir);
        if(min(nx,ny)<0 || max(nx,ny)>100 || vis[{nx,ny,dir}]) {x=nx,y=ny; break;}
        if(A[nx][ny]) dir=(dir+1)%4;
        else x=nx, y=ny, ++cnt;
    }

    return {vis[{x,y,dir}], dir, res};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    while(cin >> n && n) {
        memset(A, 0, sizeof(A));
        ll a,b,d; cin >> a >> b >> d;
        vector<pair<ll,ll>> v(n);
        for(auto &[i,j]:v) cin >> i >> j, A[i][j]=1;
        
        auto [idx, dir, cyc] = f(a, b);
        if(cyc.size() > d) {
            cout << cyc[d].first << ' ' << cyc[d].second << '\n';
        } else if(idx) { // cyc
            idx-=1;
            vector<pair<ll,ll>> cycle(cyc.begin()+idx, cyc.end());
            d-=idx;
            d%=cycle.size();
            cout << cycle[d].first << ' ' << cycle[d].second << '\n';
        } else { // not cyc
            auto [x,y] = cyc.back();
            d-=cyc.size()-1;
            cout << x+dd[dir].first*d << ' ' << y+dd[dir].second*d << '\n';
        }
    }
    return 0;
}