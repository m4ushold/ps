#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N;
double W[16][16], D[1<<16][16];

double dist(pair<int,int> a, pair<int,int> b) {
    return hypot(a.first-b.first, a.second-b.second);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<pair<int,int>> v(N);
    for(auto &[x,y]:v) cin >> x >> y;

    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(i!=j) W[i][j]=dist(v[i], v[j]);
    for(int i=0;i<1<<16;i++) for(int j=0;j<N;j++) D[i][j]=1e9;

    D[0][0]=0;
    for(int i=0;i<1<<N;i++) for(int j=0;j<N;j++) if((~i&(1<<j))) {
        for(int e=0;e<N;e++) if(W[e][j] && D[i][e] < 1e9) {
            D[i|(1<<j)][j] = min(D[i|(1<<j)][j], D[i][e] + W[e][j]);
        }
    }

    cout << fixed << setprecision(12) << D[(1<<N)-1][0];
    return 0;
}