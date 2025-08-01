#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1<<20;
int N, P[sz], IN[sz], OUT[sz], II;
vector<int> G[sz], I[sz];
void dfs(int v, int b=-1) {
    IN[v]=++II;
    for(auto i:G[v]) if(i!=b) {
        P[i]=v;
        dfs(i,v);
        I[v].push_back(IN[i]);
    }
    OUT[v]=II;
}

void sol() {
    int q; cin >> q;
    vector<int> v;
    N=1;
    for(int i=0,x;i<q;i++) {
        char op; cin >> op >> x;
        if(op == 'D') G[x].push_back(++N);
        else v.push_back(x);
    }
    II=0;
    dfs(1);

    int p=1;
    for(auto i:v) {
        if(i==p) {
            cout << p << '\n';
            continue;
        } else if(IN[p] <= IN[i] && IN[i] <= OUT[p]) {
            int j = upper_bound(I[p].begin(),I[p].end(),IN[i])-I[p].begin();
            p=G[p][j-1];
        } else p=P[p];
        cout << p << '\n';
    }

    for(int i=1;i<=N;i++) G[i].clear(), I[i].clear();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}