#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll dist(ll x, ll y) {
    return x*x+y*y;
}

void sol(int tc) {
    ll n,l; cin >> n >> l;
    priority_queue<ll,vector<ll>,greater<>> pq;
    vector<array<ll,3>> pts;
    for(int i=0;i<n;i++) {
        ll x,y,c; cin >> x >> y >> c;
        if(l*l >= dist(x,y)) {
            pts.push_back({x,y,c});
        }
    }
    sort(all(pts),[](array<ll,3> a, array<ll,3> b){
        return dist(a[0], a[1]) > dist(b[0], b[1]);
    });
    ll sum=0, res=0;
    for(auto [x,y,c]:pts) {
        sum += c, pq.push(c);
        while(l-pq.size()+1 < 0 || dist(x,y) > (l-pq.size()+1)*(l-pq.size()+1)) sum-=pq.top(), pq.pop();
        res=max(res,sum);
    }
    cout << res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}