#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int sz = 1<<18;
int N, M, P[sz], S[sz],C[sz];
vector<int> G[sz];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int dfs(int v) {
    int res=0;
    for(int i:G[v]) {
        if(C[i] && C[i] == C[v]) {
            return 1;
        } else if(C[i] == 0) {
            C[i] = C[v]&1 ? 2 : 1;
            res |= dfs(i);
        }
    }
    return res;
}

void sol(int tc) {
    cin >> N >> M;
    init(N);
    vector<pll> d;
    for(int i=0;i<M;i++) {
        int op,a,b; cin >> op >> a >> b;
        if(op == 1) {
            for(int l=a,r=b;l<=r;l++,r--) Union(l,r);
        } else d.push_back({a,b});
    }

    for(auto [a,b]:d) {
        a = Find(a), b = Find(b);
        if(a==b) {
            cout << "No";
            return;
        } else {
            G[a].push_back(b), G[b].push_back(a);
        }
    }
    for(int i=1;i<=N;i++) if(i == P[i] && C[i] == 0) {
        int x =dfs(i);
        if(x) {
            cout << "No";
            return;
        }
    }
    cout << "Yes" << endl;
    for(int i=1;i<=N;i++) {
        cout << (C[Find(i)]&1 ? 'A' : 'B');
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}