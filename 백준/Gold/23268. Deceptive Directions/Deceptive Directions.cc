#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
char M[1010][1010], ans[1010][1010];
bool vis[1010][1010];
int dist[1010][1010];
void solve(){
    int n, m; cin >> m >> n;
    int sx = -1, sy = -1;
    for(int s=1; s<=n; s++)for(int e=1; e<=m; e++){
        cin >> M[s][e], ans[s][e] = M[s][e];
        if(M[s][e] == 'S')sx = s, sy = e;
    }
    string k; cin >> k;
    map<char, array<P, 3>>dir;
    dir['N'] = {P(0, -1), P(0, 1), P(1, 0)};
    dir['S'] = {P(0, -1), P(0, 1), P(-1, 0)};
    dir['E'] = {P(-1, 0), P(0, -1), P(1, 0)};
    dir['W'] = {P(-1, 0), P(0, 1), P(1, 0)};
    queue<array<ll, 3>>qq; qq.push({sx, sy, 0}); vis[sx][sy] = 1;
    while(qq.size()){
        auto [s, e, d] = qq.front(); qq.pop();
        for(auto [x, y] : {P(s, e+1), P(s, e-1), P(s-1, e), P(s+1, e)}){
            if(x < 1 || x > n || y < 1 || y > m || vis[x][y] || M[x][y] == '#')continue;
            vis[x][y] = 1; dist[x][y] = d+1;
            qq.push({x, y, d+1});
        }
    }

    memset(vis, 0, sizeof vis);
    queue<array<ll, 3>>q; q.push({sx, sy, 0}); vis[sx][sy] = 1;
    while(q.size()){
        auto [s, e, d] = q.front(); q.pop();
        if(d == k.size() && dist[s][e] == d){
            ans[s][e] = '!';
            continue;
        }
        for(auto [dx, dy] : dir[k[d]]){
            int x = s + dx, y = e + dy;
            if(x < 1 || x > n || y < 1 || y > m || vis[x][y] || M[x][y] == '#')continue;
            vis[x][y] = 1;
            q.push({x, y, d+1});
        }
    }
    for(int s=1; s<=n; s++){
        for(int e=1; e<=m; e++)cout << ans[s][e]; cout << "\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while(T--)solve();
}