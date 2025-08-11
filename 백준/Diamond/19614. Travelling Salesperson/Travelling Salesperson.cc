#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

char G[2020][2020];

void add(list<int> &path, int v) {
    if(path.size()<2) {path.push_back(v); return;}

    int a=*path.begin(), b=*(--path.end());
    if(G[a][v]=='R') path.push_front(v);
    else if(G[b][v]=='B') path.push_back(v);
    else if(G[a][b]=='R') path.push_front(b), path.pop_back(), path.push_front(v);
    else path.push_back(a), path.pop_front(), path.push_back(v);
}

void sol(int id) {
    int n; cin >> n;
    for(int i=2;i<=n;i++) {
        for(int j=1;j<i;j++) cin >> G[i][j], G[j][i]=G[i][j];
    }

    for(int i=1;i<=n;i++) {
        list<int> path;
        for(int j=1;j<=n;j++) if(j!=i) add(path, j);
        add(path, i);
        if(*path.begin() != i) reverse(path.begin(),path.end());
        cout << n << '\n';
        for(int i:path) cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}