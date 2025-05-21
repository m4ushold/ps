#include <bits/stdc++.h>
using namespace std;

const int sz=1<<18;
int N, C[sz];
vector<int> G[sz];

bool dfs(int v=1, int c=1) {
    if(C[v]) return C[v]==c;
    C[v]=c;
    for(int i:G[v]) if(!dfs(i,-c)) return 0;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=0,s,e;i<N;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);
    cout << (dfs() ? 2 : 3);
    return 0;
}