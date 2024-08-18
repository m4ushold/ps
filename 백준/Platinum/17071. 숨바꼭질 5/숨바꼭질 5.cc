#include <bits/stdc++.h>
using namespace std;

int N, K, F[2][505050];

int bfs() {
    queue<pair<int, int>> q;
    q.push({N, 0});
    F[0][N]=1;

    while(!q.empty()) {
        auto [a,t] = q.front(); q.pop();
        int p=K+t*(t+1)/2;
        if (p > 500000) return -1;
        if (F[t % 2][p]) return t;
  
        ++t;
        for(auto i:{a+1, a-1, a*2}) {
            if(0<=i && i<=500'000 && !F[t%2][i]) {
                F[t%2][i]=1;
                q.push({i, t});
            }
        }
    } 

    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K, cout << bfs();
    return 0;
}