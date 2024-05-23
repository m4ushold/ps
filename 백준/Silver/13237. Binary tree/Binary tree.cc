#include <bits/stdc++.h>
using namespace std;

int D[22];
vector<int> G[22];

void dfs(int v) {
    for(int i:G[v]) D[i]=D[v]+1, dfs(i);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int r=0;
    for(int i=1,p;i<=n;i++) {
        cin >> p;
        if(p==-1) r=i;
        else G[p].push_back(i);
    }
    dfs(r);
    for(int i=1;i<=n;i++) cout << D[i] << '\n';
    return 0;
}