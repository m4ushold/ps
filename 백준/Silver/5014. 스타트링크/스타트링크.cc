#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int D[1010101], V[1010101];

void bfs(int f, int s, int g, int u, int d) {
    queue<int> q; q.push(s);
    V[s]=1;
    while(q.size()) {
        int v = q.front(); q.pop();
        int i = v+u, j=v-d;
        if(i<=f&&!V[i]) q.push(i), D[i]=D[v]+1, V[i]=1;
        if(j>=1&&!V[j]) q.push(j), D[j]=D[v]+1, V[j]=1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int f,s,g,u,d; cin >> f >> s >> g >> u >> d;
    bfs(f,s,g,u,d);
    if(V[g]) cout << D[g];
    else cout << "use the stairs";
}