#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, X[202020], C[202020], B;

bool chk(ll r) {
    ll mn=LLONG_MAX, cost=0;
    X[0]=X[1];
    X[N+1] = LLONG_MAX;
    for(int i=1;i<=N+1;i++) {
        if(X[i]-X[i-1] > r) {
            cost += mn;
            mn = C[i];
        } else mn=min(mn,C[i]);
    }
    return cost<=B;
}

void sol(int tc) {
    cin >> N;
    vector<pll> v(N);
    for(int i=0;i<N;i++) cin >> v[i].first;
    for(int i=0;i<N;i++) cin >> v[i].second;
    sort(all(v));
    for(int i=1;i<=N;i++) tie(X[i],C[i]) = v[i-1];
    cin >> B;

    ll l=1, r=1e9;
    while(l<r) {
        ll m=l+r>>1;
        if(chk(m)) r=m;
        else l=m+1;
    }
    cout << r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}