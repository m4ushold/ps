#include <bits/stdc++.h>
using namespace std;

int A[101010], P[101010], N, Q;
set<int> S[101010];

int Find(int v) { return P[v]==v? v: P[v]=Find(P[v]); }
void Union(int u, int v) {
    u=Find(u), v=Find(v);
    if(S[u].size()>S[v].size()) swap(u,v);
    if (u!=v) {
        P[u]=v;
        for(int i:S[u]) S[v].insert(i);
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=2,a;i<=N;i++) cin >> A[i];
    for(int i=1,a;i<=N;i++) cin >> a, S[i].insert(a), P[i]=i;

    vector<pair<int,int>> q(N-1+Q);
    for(int i=0;i<N-1+Q;i++) cin >> q[i].first >> q[i].second;

    vector<int> ans;
    for(int i=q.size()-1;i>=0;i--) {
        auto [x,a] = q[i];
        if (x==1) Union(a,A[a]);
        else ans.push_back(S[Find(a)].size());
    }
    for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << '\n';

    return 0;
}