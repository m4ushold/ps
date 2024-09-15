#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Seg {
    static const int sz=1<<17;
    vector<int> T[sz<<1];
    void bld() { 
        for(int i=sz-1;i>=1;i--) {
            T[i].resize(T[i*2].size()+T[i*2+1].size());
            merge(T[i*2].begin(),T[i*2].end(), T[i*2+1].begin(),T[i*2+1].end(), T[i].begin());
        }
    }
    vector<int>& operator[](int i) {return T[sz|i];}
    ll qry(int l, int r, int c) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=T[l].end()-upper_bound(T[l].begin(),T[l].end(),c), l++;
            if(~r&1) ret+=T[r].end()-upper_bound(T[r].begin(),T[r].end(),c), r--;
        }
        return ret;
    }
} seg;

int N, IN[101010], OUT[101010], P[101010];
vector<int> G[101010];

void dfs(int v=1) {
    static int pv=0;
    IN[v]=++pv;
    for(int i:G[v]) dfs(i);
    OUT[v]=pv;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> P[i];
    for(int i=2,p;i<=N;i++) cin >> p, G[p].push_back(i);
    dfs();
    for(int i=1;i<=N;i++) seg[seg.sz|IN[i]].push_back(P[i]);
    seg.bld();

    for(int i=1;i<=N;i++) {
        cout << seg.qry(IN[i], OUT[i], P[i]) << '\n';
    }
    return 0;
}