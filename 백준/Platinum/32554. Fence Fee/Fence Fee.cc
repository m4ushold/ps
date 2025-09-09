#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pt=pair<int,int>;

void sol(int tc) {
    int n; cin >> n;
    map<pt,vector<pt>> g;
    for(int i=0;i<n;i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        pt p = {a,b}, q = {c,d};
        g[p].push_back(q), g[q].push_back(p);
    }
    for(auto &[p,vec]:g) {
        sort(vec.begin(),vec.end(),[&](pt &a, pt &b){
            return atan2(a.y-p.y,a.x-p.x) < atan2(b.y-p.y,b.x-p.x);
        });
    }
    double ans=0;

    map<pair<pt,pt>,bool> vis;
    for(auto [s,vec]:g) {
        for(pt e:vec) if(!vis[{s,e}]) {
            pt u=s,v=e;
            vector<pt> p;
            while(!vis[{u,v}]) {
                vis[{u,v}]=1;
                p.push_back(u);
                auto &adj = g[v];
                int i = find(adj.begin(),adj.end(),u)-adj.begin();
                u=v,v=adj[(i+1)%adj.size()];
            }

            double a = 0;
            for (size_t i = 0; i < p.size(); ++i) {
                pt p1 = p[i], p2 = p[(i + 1) % p.size()];
                a += (double)p1.x * p2.y - (double)p2.x * p1.y;
            }
            a/=2;
            if(a < 0) ans += a * a;
        }
    }
    cout << fixed << setprecision(12) << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}