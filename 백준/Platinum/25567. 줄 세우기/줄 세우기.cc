#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, R[202020], P[202020], I[202020];
deque<int> D[202020];
vector<ll> A[202020];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {
    if((u=Find(u)) == (v=Find(v))) return 0;
    if(D[u].size() > D[v].size()) {
        for(auto i:D[v]) D[u].push_back(i);
        P[v]=u;
    } else {
        while(D[u].size()) D[v].push_front(D[u].back()), D[u].pop_back();
        P[u]=v;
    }
    return 1;
}

void sol(int tc) {
    cin >> N;
    int mx=0;
    for(int i=1;i<=N;i++) {
        int len, r; cin >> len >> r;
        D[r].push_back(r), mx=max(mx,r);
        for(int j=0,x;j<len-1;j++) {
            cin >> x, D[r].push_back(x), mx=max(mx,x);
        }
    }
    init(mx);
    for(int i=1;i<=mx;i++) {
        for(int j:D[i]) P[j]=D[i].front();
    }

    int q; cin >> q;
    vector<array<int,3>> qry(q);
    int idx=0;
    for(auto &[a,b,c]:qry) {
        cin >> a >> b >> c;
        if(a==1) R[idx] = Union(b,c);
        else R[idx] = Find(b) == Find(c) ? 1 : -1;
        ++idx;
    }

    for(int i=1;i<=mx;i++) if(i==P[i]) {
        A[i].push_back(0);
        for(int j:D[i]) I[j]=A[i].size(), A[i].push_back(A[i].back()+j);
    }

    for(int i=0;i<q;i++) {
        auto [op,a,b] = qry[i];
        if(op==2 && R[i]!=-1) {
            int r = Find(a);
            int s = min(I[a], I[b]), e = max(I[a], I[b]);
            R[i] = A[r][e] - A[r][s-1];
        }
    }
    
    for(int i=0;i<q;i++) {
        if(qry[i][0] == 1) cout << (R[i] ? "YES":"NO") << '\n';
        else cout << R[i] << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}