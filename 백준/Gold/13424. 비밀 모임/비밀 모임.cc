#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, K, D[101][101];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> N >> M;
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) D[i][j]=1e9;
        for(int i=1;i<=N;i++) D[i][i]=0;
        for(int i=1,s,e,w;i<=M;i++) cin >> s >> e >> w, D[s][e]=D[e][s]=w;

        for(int k=1;k<=N;k++) {
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=N;j++) D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
            }
        }
        cin >> K;
        vector<int> v(K);
        for(int &i:v) cin >> i;
        ll mn=1e9, idx=0;
        for(int i=1;i<=N;i++) {
            ll a=0;
            for(int j:v) a+=D[i][j];
            if(mn>a) mn=a, idx=i;
        }
        cout << idx << '\n';
    }
    

    return 0;
}