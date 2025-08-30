#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
const int N = 1'000'101;
vector<int> G[N];
int Siz[N];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int s = 2; s <= n; s++) {
        int p; cin >> p; p++;
        G[p].push_back(s);
    }
    auto dfs = [&] (auto &&self,int v)-> void {
        int mx = 0;
        for (int nx : G[v]) {
            self(self, nx);
            mx = max(Siz[nx], mx);
        }
        Siz[v] = mx + 1;
        sort (all(G[v]), [&] (int a,int b){
            return Siz[a] > Siz[b];
        });
    };
    dfs(dfs, 1);
    vector<int> dep;
    auto dfs2 = [&] (auto &&self,int v,int d)-> void {
        int c = 0;
        for (int nx : G[v]) {
            self(self, nx, c ? 1 : d+1);
            c++;
        }
        if (!c) dep.push_back(-d);
    };
    dfs2(dfs2, 1, 1);
    sort (all(dep));
    while (k > 0 && dep.size()) {
        int v = -dep.back(); dep.pop_back();
        if (v > k) v -= k, k = 0, dep.push_back(-v);
        else k -= v;
    }
    cout << dep.size() << "\n";
}