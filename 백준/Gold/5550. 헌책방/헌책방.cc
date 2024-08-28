#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, K, D[11][2020], L[11];
vector<ll> B[11];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(ll i=1,c,g;i<=N;i++) cin >> c >> g, B[g].push_back(c);

    for(int i=1;i<=10;i++) {
        sort(B[i].begin(),B[i].end(),greater<>()), B[i].insert(B[i].begin(),0);
        for(int j=1;j<B[i].size();j++) B[i][j]+=B[i][j-1];
        for(int j=1;j<B[i].size();j++) B[i][j]+=j*(j-1);
    }

    int cnt=0;
    for(int g=1;g<=10;g++) {
        int len = B[g].size();
        for(int i=1;i<=min(cnt+len-1, (int)K);i++) {
            for(int j=0;j<len && i>=j;j++) D[g][i] = max(D[g][i], D[g-1][i-j] + B[g][j]);
        }
        cnt = min(len + cnt, (int)K);
    }
    cout << D[10][K];
    return 0;
}