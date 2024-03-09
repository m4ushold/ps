#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int G[10101][2];
vector<int> W[10101];

void f(int v, int d=0) {
    static int idx=1;
    if(G[v][0]>0) f(G[v][0],d+1);
    W[d].push_back(idx), ++idx;
    if(G[v][1]>0) f(G[v][1],d+1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll root=n*(n+1)/2;
    for(int i=0,v;i<n;i++) {
        cin >> v >> G[v][0] >> G[v][1];
        root -= (G[v][0]<0 ? 0:G[v][0]) + (G[v][1]<0 ? 0:G[v][1]);
    }
    f(root);

    int j=0,mx=0;
    for(int i=0;i<10101;i++) {
        if(!W[i].empty() && mx<W[i].back()-W[i][0]) mx=W[i].back()-W[i][0], j=i;
    }
    cout << j+1 << ' ' << mx+1;
    return 0;
}