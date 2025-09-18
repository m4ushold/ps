#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, M, C, D, A[202], DP[2][25252];

ll f(ll x) {
    int y = D/C;

    for(int i=0;i<=M;i++) DP[0][i]=DP[1][i]=0;
    for(int i=1;i<=N;i++) {
        deque<pair<ll,ll>> dq;
        for(int j=0;j<=(M-x)/C;j++) {
            if(x==0 && j==0) continue;
            while(dq.size() && dq.front().second < j-y) dq.pop_front();
            while(dq.size() && dq.back().first <= DP[~i&1][j]) dq.pop_back();
            dq.push_back({DP[~i&1][j],j});
            DP[i&1][j] = dq.front().first;
        }
        dq.clear();
        for(int j=(M-x)/C;j>=0;j--) {
            if(x==0 && j==0) continue;
            while(dq.size() && dq.front().second > j+y) dq.pop_front();
            while(dq.size() && dq.back().first <= DP[~i&1][j]) dq.pop_back();
            dq.push_back({DP[~i&1][j],j});
            DP[i&1][j] = max(DP[i&1][j], dq.front().first);
        }

        for(int j=0;j<=(M-x)/C;j++) {
            if(x==0 && j==0) continue;
            DP[i&1][j]+=M-abs((j*C+x)-A[i]);
        }
    }

    return *max_element(DP[N&1], DP[N&1]+25252);
}

void sol(int tc) {
    cin >> N >> M >> C >> D;
    for(int i=1;i<=N;i++) cin >> A[i];
    ll ans=0;
    for(int i=0;i<C;i++) ans=max(ans,f(i));
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}