#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, A[1010][1010];
pll I[1010101];

struct dsu {
    int n;
    vector<int> p, x;
    dsu(int n) : p(n,-1), n(n), x(n,0) {
        iota(all(x),0);
    }
    int leader(int a) { return p[a] < 0 ? a : p[a] = leader(p[a]); }
    int size(int a) { return -p[leader(a)]; }
    int xor_size(int a) { return x[leader(a)]; }
    bool same(int a, int b) { return leader(a) == leader(b); }
    int merge(int a, int b) {
        return (a = leader(a)) != (b = leader(b)) && (-p[a] < -p[b] ? swap(a,b) : void(), p[a]+=p[b], x[a]^=x[b], p[b]=a, true);
    }
};

void sol(int tc) {
    cin >> N >> M;
    vector<int> v;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        int x; cin >> x;
        I[x] = {i,j};
        v.push_back(x);
    }
    for(int i=0;i<=N+1;i++) for(int j=0;j<=M+1;j++) A[i][j]=-1;

    dsu d(1010101);
    vector<pll> dir({
        {1,0},{0,1},{-1,0},{0,-1}
    });

    sort(rall(v));
    ll ans=0, mx=0;
    for(int i:v) {
        auto [x,y] = I[i];
        A[x][y] = i;
        ans += i;
        for(auto [dx,dy]:dir) {
            int j = A[x+dx][y+dy];
            if(j>=0 && !d.same(i,j)) {
                ans -= d.xor_size(i) + d.xor_size(j);
                d.merge(i,j);
                ans += d.xor_size(i);
            }
        }
        mx = max(mx, ans);
    }
    cout << mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}