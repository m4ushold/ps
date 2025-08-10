#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, K, C[5050];

void sol(int tc) {
    cin >> N >> K;

    for(int i=1;i<=K;i++) {
        for(int j=1;j<=N;j++) {
            int x; cin >> x;
            C[x]+=j;
        }
    }
    vector<pair<int,int>> v;
    for(int i=1;i<=N;i++) v.push_back({C[i],i});
    sort(v.begin(),v.end());
    for(auto [i,j]:v) cout << j << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}