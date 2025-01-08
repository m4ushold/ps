#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, W[5050505];

ll f(ll c, ll w) {
    ll a = c/w;
    return a*a*(w-c%w) + (a+1)*(a+1)*(c%w);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<N;i++) cin >> W[i];
    vector<pair<int,int>> v;
    for(int i=1,s,e,w;i<=M;i++) {
        cin >> s >> e >> w;
        v.push_back({s,w});
        v.push_back({e,-w});
    }
    sort(v.begin(),v.end(),greater<>());

    ll c=0;
    for(int i=2;i<=N;i++) {
        while(v.size() && v.back().first<i) c+=v.back().second, v.pop_back();
        cout << f(c,W[i-1]) << '\n';
    }
    return 0;
}