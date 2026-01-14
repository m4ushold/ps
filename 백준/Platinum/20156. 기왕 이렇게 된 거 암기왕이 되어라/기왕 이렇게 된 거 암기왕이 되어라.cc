#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, K, P[101010], R[101010], C[101010];
vector<array<int,3>> Q[101010];

struct dsu {
    int n;
    vector<int> p;
    dsu(int n) : p(n,-1), n(n) {}
    int leader(int a) { return p[a] < 0 ? a : p[a] = leader(p[a]); }
    int size(int a) { return -p[leader(a)]; }
    bool same(int a, int b) { return leader(a) == leader(b); }
    int merge(int a, int b) {
        return (a = leader(a)) != (b = leader(b)) && (-p[a] < -p[b] ? swap(a,b) : void(), p[a]+=p[b], p[b]=a, true);
    }
};

void sol(int tc) {
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) cin >> P[i];
    vector<int> v(M);
    for(int &i:v) cin >> i, C[i]++;

    dsu d(N+1);
    for(int i=0,a,b,c;i<K;i++) cin >> a >> b >> c, Q[a].push_back({b,c,i});
    for(int i=1;i<=N;i++) if(C[i]==0 && P[i]>0) d.merge(i,P[i]);

    for(int i=M;i>=0;i--) {
        for(auto [a,b,j]:Q[i]) R[j] = d.same(a,b);
        if(i-1>=0 && P[v[i-1]]>0 && --C[v[i-1]] == 0) d.merge(v[i-1], P[v[i-1]]);
    }
    for(int i=0;i<K;i++) cout << (R[i] ? "Same Same;" : "No;") << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}