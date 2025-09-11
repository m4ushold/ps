#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, Q, I[303030], V[303030], IN[303030], OUT[303030];
vector<int> G[303030];

int dfs(int v) {
    static int pv=0;
    V[v]=1;
    IN[v]=++pv;
    for(int i:G[v]) {
        if(V[i]) return 1;
        dfs(i);
    }
    OUT[v]=pv;
    return 0;
}

void sol(int tc) {
    cin >> N >> M >> Q;
    for(int i=1;i<=M;i++) {
        int s,e;
        char c;
        cin >> s >> e >> c;
        s--, e--;
        s*=3, e*=3;
        if(c == 'x') e++;
        else if(c == 'y') s++, e+=2;
        else s+=2;
        G[e].push_back(s), I[s]++;
    }
    for(int i=0;i<3*N;i++) if(!I[i] && dfs(i)) {
        for(int i=0;i<Q;i++) cout << "1\n";
        return;
    }
    for(int i=0;i<3*N;i++) if(I[i] && !V[i]) {
        for(int i=0;i<Q;i++) cout << "1\n";
        return; 
    }
    for(int i=0;i<Q;i++) {
        int s,e;
        char c;
        cin >> s >> e >> c;
        s--, e--;
        s*=3, e*=3;
        if(c == 'x') e++;
        else if(c == 'y') s++, e+=2;
        else s+=2;

        if(IN[s] <= IN[e] && IN[e] <= OUT[s]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}